/* 
* @Author: sxf
* @Date:   2015-12-25 20:40:43
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-26 16:37:59
*/


#ifndef PACKAGE_JIT_H
#define PACKAGE_JIT_H

#include <string>

class PackageJIT_private;
class MetaScriptRunner;
namespace llvm {
	class ExecutionEngine;
};

class PackageJIT
{
public:
	static void LoadPlugin(const std::string& path, const std::string& name, MetaScriptRunner* msr);
	static void AddSymbol(const std::string& name, void* ptr);
	static PackageJIT_private* getInstance();

private:
	PackageJIT();
	~PackageJIT();
	static PackageJIT_private* priv;
};


#endif // PACKAGE_JIT_H
