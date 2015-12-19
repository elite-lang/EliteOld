/* 
* @Author: sxf
* @Date:   2015-11-08 10:20:02
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-19 16:28:53
*/

#include "Builder.h"
#include "Worker.h"
#include "PathGetter.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <streambuf>
using namespace std;

// 构建一个文件
int Builder::BuildFile(std::string filename) {
	if (!PathGetter::testFile(filename.c_str())) {
		printf("输入文件异常 %s\n", filename.c_str());
		exit(0);
	}

	string buildpath = this->buildpath;
	buildpath += make_default_name(filename.c_str());

	string program = get_file_name(filename.c_str());

	string objname = program + ".o";
	string data = fileReader(filename.c_str());
	printf("输入文件: %s \n输出文件: %s\n", filename.c_str(), buildpath.c_str());
	worker->Run(data.c_str(), buildpath.c_str());

	call_llc(buildpath);
	printf("输入文件: %s \n输出文件: %s\n", (this->buildpath + objname).c_str(), 
		(this->buildpath + program).c_str());
	call_ld( this->buildpath + objname, this->buildpath + program );

	return 0;
}


// 构建其中指定的路径
int Builder::BuildPath(std::string filepath, bool isRecursive) {
	return 0;
}

// 添加一个链接文件, 如果是bc的话, 会自动用llc编译成本地文件, 如果是.o则直接链接
int AddLinkFile(std::string filename) {
	return 0;
}


// 添加一个链接路径
int AddLinkPath(std::string filepath) {
	return 0;
}

// 扫描SearchPath下的全部符号
int Builder::PreBuildAll() {
	return 0;
}


// 添加源代码的搜索路径
int Builder::AddSearchPath(std::string path) {
	return 0;
}


// 添加库路径
int Builder::AddLibPath(std::string path) {
	return 0;
}

int Builder::SetBuildPath(std::string path) {
	buildpath = path;
	return 0;
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

std::string Builder::fileReader(const char* path) {
    std::ifstream t(path, std::ios::binary);
	std::string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	            std::istreambuf_iterator<char>());
    return str;
}
string Builder::make_default_name(const char* filename) {
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
	string s = str;
	delete str;
	return s;
}

string Builder::get_file_name(const char* filename) {
	const char* ans = strrchr(filename, '/');
	const char* file;
	if (ans == 0) file = filename;
	else file = ans+1;
	int size = 0;
	for (const char* p = file; *p != 0; ++p, ++size)
		if (*p == '.') break;
	char* str = new char[size+1];
	strncpy(str, file, size);
	str[size] = 0;
	string s = str;
	delete[] str;
	return s;
}

int Builder::call_llc(std::string filein) {
	
#if defined(__linux__) || defined(__APPLE__)
	string llc = PathGetter::getEliteToolsPath();
	llc += "/llvm-3.6/llc";
	string args = " -filetype=obj "+filein;
	llc += args;
	return system(llc.c_str());
#endif
#if defined(_WIN32)
	string llc = PathGetter::getEliteToolsPath();
	llc += "\\llvm-3.6\\llc.exe";
	string args = filein + " -filetype=obj ";
	llc += args;
	return system(llc.c_str());
#endif
	return 0;
}

int Builder::call_ld(std::string filein, std::string fileout) {

#if defined(__linux__) || defined(__APPLE__)
	string ld = "clang++";
	string runtime = " -L";
	runtime += PathGetter::getEliteToolsPath();
	runtime += "/runtime/";
	string args = " -lruntime";
	args += runtime + " -o " + fileout + " " + filein;
	ld += args;
	return system(ld.c_str());
#endif
#if defined(_WIN32)
	
#endif
	return 0;
}

