/*
* @Author: sxf
* @Date:   2015-12-26 09:51:14
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-26 22:00:20
*/

#include "PackageJIT.h"
#include <string>
#include <iostream>
#include "MetaScriptRunner.h"
#include "ICodeGenContext.h"

#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/Verifier.h"
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
#include "llvm/Support/Debug.h"


using namespace llvm;
using namespace std;

class CodeGenContext;
typedef void (*func_type)(CodeGenContext*);

class PackageJIT_private
{
public:
	PackageJIT_private() {
		InitializeNativeTarget();
		InitializeNativeTargetAsmPrinter();
		InitializeNativeTargetAsmParser();
	}
	~PackageJIT_private() {
		delete EE;
	}
	LLVMContext context;
	ExecutionEngine* EE = NULL;
	RTDyldMemoryManager* RTDyldMM = NULL;

	void initEE(std::unique_ptr<Module> Owner) {
		string ErrStr;
		if (EE == NULL) {
			RTDyldMM = new SectionMemoryManager();
			EE = EngineBuilder(std::move(Owner))
				.setEngineKind(EngineKind::JIT)
				.setErrorStr(&ErrStr)
				.setVerifyModules(true)
				.setMCJITMemoryManager(std::unique_ptr<RTDyldMemoryManager>(RTDyldMM))
				.setOptLevel(CodeGenOpt::Default)
				.create();

		} else
			EE->addModule(std::move(Owner));
		if (ErrStr.length() != 0)
			cerr << "Create Engine Error" << endl << ErrStr << endl;
		EE->finalizeObject();
	}

	void LoadPlugin(const std::string& path, const std::string& name, MetaScriptRunner* msr) {

		SMDiagnostic error;
		std::unique_ptr<Module> Owner = parseIRFile(path, error, context);
		if(Owner == nullptr) {
			cout << "Load Error: " << path << endl;
			Owner->dump();
			return;
		}

		initEE(std::move(Owner));

		string func_name = name + "_elite_plugin_init";

		uint64_t func_addr = EE->getFunctionAddress(func_name.c_str());
		if (func_addr == 0) {
			printf("错误, 找不到函数: %s\n", func_name.c_str());
			return;
		}
		func_type func = (func_type) func_addr;
		func(msr->getCodeGenContext());
	}

	void RunPlugin(const std::string& name, MetaScriptRunner* msr) {
		// string func_name = name + "_elite_plugin_init";
		//
		// uint64_t func_addr = EE->getFunctionAddress(func_name.c_str());
		// if (func_addr == 0) {
		// 	printf("错误, 找不到函数: %s\n", func_name.c_str());
		// 	return;
		// }
		// func_type func = (func_type) func_addr;
		// func(msr->getCodeGenContext());

		// 给解释器使用的部分
		// Function* func = EE->FindFunctionNamed(func_name.c_str());
		// if (func == NULL) {
		// 	printf("忽略, 找不到函数: %s\n", func_name.c_str());
		// 	return;
		// }
		// std::vector<GenericValue> args;
		// args.push_back(GenericValue((ICodeGenContext*)(msr->getCodeGenContext())));
		// EE->runFunction(func, args);
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

void PackageJIT::RunPlugin(const std::string& name, MetaScriptRunner* msr) {
	getInstance()->RunPlugin(name, msr);
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
