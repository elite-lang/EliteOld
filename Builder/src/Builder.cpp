/* 
* @Author: sxf
* @Date:   2015-11-08 10:20:02
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 10:32:45
*/

#include "Builder.h"

// 构建一个文件
int Builder::BuildFile(std::string filename) {

}


// 构建其中指定的路径
int Builder::BuildPath(std::string filepath, bool isRecursive) {

}


// 扫描SearchPath下的全部符号
int Builder::PreBuildAll() {

}


// 添加源代码的搜索路径
int Builder::AddSearchPath(std::string path) {

}


// 添加库路径
int Builder::AddLibPath(std::string path) {

}


void Builder::setParser(Parser* parser) {
	this->parser = parser;
}


// 构建Builder，需要初始化好的Parser
Builder* Builder::Create(Parser* parser) {
	Builder* b = new Builder();
	b->setParser(parser);
	return b;
}

Builder::Builder() {

}

Builder::~Builder() {

}
