/*
* @Author: sxf
* @Date:   2015-12-25 20:40:43
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-29 12:30:59
*/


#ifndef PACKAGE_JIT_H
#define PACKAGE_JIT_H

#include <string>

class PackageJIT_private;
class MetaScriptRunner;
namespace llvm {
	class ExecutionEngine;
};


/**
 * @brief C插件的JIT解释器
 * @details 为了支持C编写跨平台的插件，我们将使用Clang，将C代码编译成llvm字节码，然后通过JIT解释执行，
 *          达到一份编译，跨平台加载的特性
 *          本类是LLVM的JIT解释器，同时是一个单例类，所有插件，都将共用该类，进行C插件的加载与运行。
 *          注意，本类并没有考虑线程安全的问题，请勿多线程调用本来进行加载。
 */
class PackageJIT
{
public:
	/**
	 * @brief 加载一款C插件
	 *
	 * @param path 插件的决定路径，指向一个epbc文件
	 * @param name 插件名，影响插件的加载入口函数
	 * @param msr MetaScriptRunner接口
	 */
	static void LoadPlugin(const std::string& path, const std::string& name, MetaScriptRunner* msr);


	static void RunPlugin(const std::string& name, MetaScriptRunner* msr);
	
	/**
	 * @brief 添加一个动态链接符号
	 * @details 由于C插件的特殊性，静态链接的函数由于符号名未导出，JIT将无法调用到，所以我们需要为C接口导出动态链接符号
	 *
	 * @param name 符号名，一般C函数就是函数名
	 * @param ptr 对应符号的地址，一般C函数为函数指针
	 */
	static void AddSymbol(const std::string& name, void* ptr);

	static PackageJIT_private* getInstance();

private:
	PackageJIT();
	~PackageJIT();
	static PackageJIT_private* priv;
};


#endif // PACKAGE_JIT_H
