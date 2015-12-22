/* 
* @Author: sxf
* @Date:   2015-11-08 10:20:02
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 11:19:18
*/

#include "Builder.h"
#include "Worker.h"
#include "PathGetter.h"
#include "FileUtils.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <streambuf>
#include "PathUtils.h"
#include "DebugMsg.h"

using namespace std;

// 构建一个文件
int Builder::BuildFile(std::string filename) {
	if (!PathGetter::testFile(filename.c_str())) {
		printf("输入文件异常 %s\n", filename.c_str());
		exit(0);
	}

	string program = get_file_name(filename.c_str());
	string outfile_path = this->buildpath + "/" + program + ".bc";
	outfile_path = PathUtils::native(outfile_path); // 本地化

	string data = fileReader(filename.c_str());
	printf("输入文件: %s \n输出文件: %s\n", filename.c_str(), outfile_path.c_str());
	worker->Run(data.c_str(), outfile_path.c_str());

	// 生成meta
	string meta_path = this->buildpath + "/meta.bc";
	meta_path = PathUtils::native(meta_path); // 本地化
	worker->MetaGen(meta_path.c_str());
	
	// 生成obj
	call_llc(outfile_path);
	call_llc(meta_path);

	string objname = this->buildpath + "/" + program + ".o";
	objname = PathUtils::native(objname); // 本地化
	string objmeta = this->buildpath + "/meta.o";
	objmeta = PathUtils::native(objmeta); // 本地化
	string program_path = this->buildpath + "/" + program;
	program_path = PathUtils::native(program_path); // 本地化

	printf("输入文件: %s \n输出文件: %s\n", objname.c_str(), program_path.c_str());
	int ret = call_ld( objname + " " + objmeta, program_path);

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
	FileUtils::create_directory(path);
	return 0;
}

void Builder::setDebugFilePath(const char* path) {
	DebugMsg::setDebugFilePath(path);
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
	
#if !defined(_WIN32) && (defined(__linux__) || defined(__APPLE__))
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

#if !defined(_WIN32) && (defined(__linux__) || defined(__APPLE__))
	string ld = "clang++";
	string runtime = " -L";
	runtime += PathGetter::getEliteToolsPath();
	runtime += "/runtime/";
	string args = runtime + " -o " + fileout + " " + filein + " -lruntime -ldyncall_s";
	ld += args;
	printf("ld: %s\n", ld.c_str());
	return system(ld.c_str());
#endif
#if defined(_WIN32)
	
#endif
	return 0;
}

