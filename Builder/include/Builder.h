/*
* @Author: sxf
* @Date:   2015-11-08 09:06:35
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 15:47:59
*/


#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "PathSet.h"

class Worker;

/**
 * @brief 项目构建器
 */
class Builder
{
public:
	// 构建一个文件
	int BuildFile(std::string filename);

	// 构建其中指定的路径
	int BuildPath(std::string package, bool isRecursive = false);

	// 自动构建源代码目录下的全部内容
	int BuildAll();

	// 添加一个链接文件, 如果是bc的话, 会自动用llc编译成本地文件, 如果是.o则直接链接
	int AddLinkFile(std::string filename);

	// 添加一个链接路径
	int AddLinkPath(std::string path);

	// 设置构建路径
	int SetBuildPath(std::string path);

	// 扫描SearchPath下的全部符号
	int PreBuildAll();

	// 添加源代码的搜索路径
	int AddSrcPath(std::string path);

	// 添加库路径
	int AddLibPath(std::string path);

	// 添加链接时参数
	int AddLinkArgs(std::string args);

	// 设置Debug过程文件生成路径
	void setDebugFilePath(const char* path);

	// 设置工作器
	void setWorker(Worker* worker);

	// 构建Builder，需要初始化好的Worker
	static Builder* Create(Worker* worker = 0);
	void Close();


	static int call_llc(std::string filein);
	static int call_ld(std::string filein, std::string fileout, std::string link_args);
protected:
	Builder(Worker* worker = 0);
	~Builder();

	Worker* worker = 0;
	std::string buildpath;
	std::string link_args;

	static std::string make_default_name(const char* filename);
	static std::string get_file_name(const char* filename);



	/**
	 * 程序源文件目录
	 */
	PathSet src_paths;

	/**
	 * 程序库目录
	 */
	PathSet lib_paths;

	/**
	 * 需要链接的C库目录
	 */
	PathSet link_paths;

};



#endif // BUILDER_H
