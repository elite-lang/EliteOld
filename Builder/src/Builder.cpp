/* 
* @Author: sxf
* @Date:   2015-11-08 10:20:02
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-11 22:08:02
*/

#include "Builder.h"
#include "Worker.h"
#include "PathGetter.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <glibmm.h>
using namespace std;

// 构建一个文件
int Builder::BuildFile(std::string filename) {
	if (!PathGetter::testFile(filename.c_str())) {
		printf("输入文件异常 %s\n", filename.c_str());
		exit(0);
	}

	string buildpath = this->buildpath;
	char* outname = make_default_name(filename.c_str());
	buildpath += outname;
	delete[] outname;

	string data = Glib::file_get_contents(filename) ;
	printf("输入文件: %s \n输出文件: %s\n", filename.c_str(), buildpath.c_str());
	worker->Run(data.c_str(), buildpath.c_str());

	return 0;
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

int Builder::SetBuildPath(std::string path) {
	buildpath = path;
}


void Builder::setWorker(Worker* worker) {
	this->worker = worker;
}


// 构建Builder，需要初始化好的Worker
Builder* Builder::Create(Worker* worker) {
	return new Builder(worker);
}

Builder::Builder(Worker* worker) {
	if (worker == 0) 
		setWorker(Worker::CreateDefault(
			PathGetter::getDefaultLexCfg(), PathGetter::getDefaultParserCfg()));
	else 
		setWorker(worker);
}

Builder::~Builder() {
	if (worker != 0) delete worker;
}

void Builder::Close() {
	delete this;
}

char* Builder::fileReader(const char* path, int& flen) {
    fstream file;
    locale::global(locale("zh_CN.UTF-8"));
    file.open(path);//打开文件
    if(!file.is_open())
    {
        printf("can not open BNF file!\n");
        return NULL;
    }
    file.seekg(0,ios::end);
    flen = file.tellg();
    file.seekg(0,ios::beg);
    char* data = new char[flen+1];
    file.read(data,flen);
    file.close();
    data[flen] = 0;
    return data;
}
char* Builder::make_default_name(const char* filename) {
	const char* ans = strrchr(filename, '/');
	const char* file;
	if (ans == 0) file = filename;
	else file = ans+1;
	int size = 0;
	for (const char* p = file; *p != 0; ++p, ++size)
		if (*p == '.') break;
	char* str = new char[size+4];
	strncpy(str, file, size+1);
	str[size+1] = 'b';
	str[size+2] = 'c';
	str[size+3] = 0;
	return str;
}
