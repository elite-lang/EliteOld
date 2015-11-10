/* 
* @Author: sxf
* @Date:   2015-11-08 09:06:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 10:19:41
*/


#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "Parser.h"
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

	// 扫描SearchPath下的全部符号
	int PreBuildAll();

	// 添加源代码的搜索路径
	int AddSearchPath(std::string path);

	// 添加库路径
	int AddLibPath(std::string path);

	void setParser(Parser* parser);

	// 构建Builder，需要初始化好的Parser
	static Builder* Create(Parser* parser);

protected:
	Builder();
	~Builder();

	Parser* parser;
};



#endif // BUILDER_H
