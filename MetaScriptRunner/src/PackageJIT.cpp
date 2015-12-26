/* 
* @Author: sxf
* @Date:   2015-12-26 09:51:14
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-26 19:21:50
*/

#include "PackageJIT.h"
#include <string>
#include <iostream>
#include "MetaScriptRunner.h"

#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include <llvm/Support/MemoryBuffer.h>
#include "llvm/Support/raw_ostream.h"
#include <llvm/Support/DynamicLibrary.h>

using namespace llvm;
using namespace std;

class PackageJIT_private
{
public:
	PackageJIT_private() {
		InitializeNativeTarget();
	}
	~PackageJIT_private() {
		delete EE;
	}
	LLVMContext context;
	ExecutionEngine* EE = NULL;

	void initEE(std::unique_ptr<Module> Owner) {
		if (EE == NULL) 
			EE = EngineBuilder(std::move(Owner)).create();
		else 
			EE->addModule(std::move(Owner));
	}

	void LoadPlugin(const std::string& path, const std::string& name, MetaScriptRunner* msr) {
		
		SMDiagnostic error;
		std::unique_ptr<Module> Owner = getLazyIRFileModule(path, error, context);
		if(Owner == nullptr) {
			cout << "Load Error: " << path << endl;
			Owner->dump();
			return;
		}

		initEE(std::move(Owner));

		string func_name = name + "_elite_plugin_init";
		Function* func = EE->FindFunctionNamed(func_name.c_str());

		std::vector<GenericValue> args;
		args.push_back(GenericValue(msr->getCodeGenContext()));
		GenericValue gv = EE->runFunction(func, args);
		// plugin_init_func init = (plugin_init_func)(intptr_t)(EE->getPointerToFunction(func));
		// init(msr->getCodeGenContext());
	}

};



PackageJIT::PackageJIT() {
}

PackageJIT::~PackageJIT() {
	delete priv;
}


void PackageJIT::LoadPlugin(const std::string& path, const std::string& name, MetaScriptRunner* msr) {
	getInstance()->LoadPlugin(path, name, msr);
}

void PackageJIT::AddSymbol(const std::string& name, void* ptr) {
	llvm::sys::DynamicLibrary::AddSymbol(name, ptr);
}

PackageJIT_private* PackageJIT::getInstance() {
	if (priv == NULL)
		priv = new PackageJIT_private();
	return priv;
}

PackageJIT_private* PackageJIT::priv = NULL;