/* 
* @Author: sxf
* @Date:   2015-11-08 09:06:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-07 11:39:38
*/


#ifndef BUILDER_H
#define BUILDER_H

#include <string>

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
	int BuildPath(std::string filepath, bool isRecursive = false);

	// 设置构建路径
	int SetBuildPath(std::string path);

	// 扫描SearchPath下的全部符号
	int PreBuildAll();

	// 添加源代码的搜索路径
	int AddSearchPath(std::string path);

	// 添加库路径
	int AddLibPath(std::string path);

	// 设置工作器
	void setWorker(Worker* worker);

	// 构建Builder，需要初始化好的Worker
	static Builder* Create(Worker* worker = 0);
	void Close();

protected:
	Builder(Worker* worker = 0);
	~Builder();

	Worker* worker = 0;
	std::string buildpath;
	static char* fileReader(const char* path, int& flen);
	static char* make_default_name(const char* filename);
};



#endif // BUILDER_H
