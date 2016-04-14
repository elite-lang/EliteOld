/*
* @Author: sxf
* @Date:   2015-11-08 10:20:02
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 15:46:40
*/

#include "Builder.h"
#include "Worker.h"
#include "PathGetter.h"
#include "FileUtils.h"
#include <cstring>
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <streambuf>
#include "PathUtils.h"
#include "DebugMsg.h"
#include "PackageChanger.hpp"
#include "CodeGen.h"
using namespace std;


class builder_scanner : public IFileTraversal {
public:
	virtual void Work(const std::string& now_path,
		const std::string& filename,
		const std::string& suffix)
	{
		printf("%s %s %s\n", now_path.c_str(), filename.c_str(), suffix.c_str());
		if (suffix == ".elite") {
			string filepath = now_path + "/" + filename;
				filepath = PathUtils::native(filepath);

			string outfile_path = this->buildpath + "/" +
				path_name + "/" + filename;
				int n = outfile_path.find(".elite");
				outfile_path.replace(n, 6, ".bc");
				outfile_path = PathUtils::native(outfile_path); // 本地化

			string data = FileUtils::fileReader(filepath.c_str());
			printf("输入文件: %s \n输出文件: %s\n", filepath.c_str(), outfile_path.c_str());
			Node* node = worker->MakeAST(data.c_str());
			file_map[outfile_path] = node;
			FileUtils::create_directories(PathUtils::parent_path(outfile_path));
		}
	}

	void MakeAll() {
		set<Node*> pset;
		for (auto item : file_map) pset.insert(item.second);
		worker->getCodegen()->PreScan(pset);

		for (auto item : file_map) {
			worker->getCodegen()->Make(item.second, item.first.c_str(), package_name.c_str());
			Builder::call_llc(item.first);
			string objname = item.first;
			int n = objname.find(".bc");
			objname.replace(n, 3, ".o");
			objname = PathUtils::native(objname); // 本地化
			objname_list += " ";
			objname_list += objname;
		}
	}

	Worker* worker;
	string buildpath;
	string package_name;
	string path_name;
	string objname_list;
	map< string, Node* > file_map;
};



// 构建一个文件
int Builder::BuildFile(std::string filename) {
	if (!PathGetter::testFile(filename.c_str())) {
		printf("输入文件异常 %s\n", filename.c_str());
		exit(0);
	}

	string program = get_file_name(filename.c_str());
	string outfile_path = this->buildpath + "/" + program + ".bc";
	outfile_path = PathUtils::native(outfile_path); // 本地化

	string data = FileUtils::fileReader(filename.c_str());
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
	int ret = call_ld( objname + " " + objmeta, program_path, link_args);

	return ret;
}


// 构建其中指定的路径(构建其中一个包)
int Builder::BuildPath(std::string package, bool isRecursive) {
	builder_scanner bs;
	bs.worker = worker;
	bs.buildpath = buildpath;
	bs.package_name = package;
	bs.path_name = PackageChanger::pname2path(package);
	printf("package_name: %s\n", package.c_str());
	printf("path_name: %s\n", bs.path_name.c_str());

	auto vec = src_paths.FindPackage(package);
	for (string& item : vec) {
		printf("package_path: %s\n", item.c_str());
		FileUtils::dir_traversal(item, bs, FileUtils::only_file);
	}
	bs.MakeAll();

	// 生成meta
	string meta_path = buildpath + "/" + bs.path_name + "/meta.bc";
	meta_path = PathUtils::native(meta_path); // 本地化
	worker->MetaGen(meta_path.c_str());
	call_llc(meta_path);

	string meta_obj = meta_path;
	int n = meta_obj.find(".bc");
	meta_obj.replace(n, 3, ".o");
	meta_obj = PathUtils::native(meta_obj); // 本地化

	string program_path = this->buildpath + "/run";
	program_path = PathUtils::native(program_path); // 本地化
	int ret = call_ld( bs.objname_list + " " + meta_obj, program_path, link_args);
	return ret;
}


int Builder::BuildAll() {


	return 0;
}


// 添加一个链接文件, 如果是bc的话, 会自动用llc编译成本地文件, 如果是.o则直接链接
int Builder::AddLinkFile(std::string filename) {
	return 0;
}


// 添加一个链接路径
int Builder::AddLinkPath(std::string path) {
	link_paths.AddPath(PathUtils::native(path));
	return 0;
}

// 扫描SearchPath下的全部符号
int Builder::PreBuildAll() {
	return 0;
}


// 添加源代码的搜索路径
int Builder::AddSrcPath(std::string path) {
	src_paths.AddPath(PathUtils::native(path));
	return 0;
}


// 添加库路径
int Builder::AddLibPath(std::string path) {
	lib_paths.AddPath(PathUtils::native(path));
	return 0;
}

int Builder::SetBuildPath(std::string path) {
	buildpath = path;
	FileUtils::create_directory(path);
	return 0;
}

int Builder::AddLinkArgs(std::string args) {
	link_args += " ";
	link_args += args;
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
	setWorker(worker);
}

Builder::~Builder() {
	if (worker != 0) delete worker;
}

void Builder::Close() {
	delete this;
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
	delete[] str;
	return s;
}

string Builder::get_file_name(const char* filename) {
	const char* ans = strrchr(filename, '/');
	const char* file;
	if (ans == 0) file = filename;
	else file = ans+1;
	int size = strrchr(file, '.') - file;
	if (size <= 0) { string s = file; return s; }
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

int Builder::call_ld(std::string filein, std::string fileout, std::string link_args) {

#if !defined(_WIN32) && (defined(__linux__) || defined(__APPLE__))
	string ld = "clang++";
#else
	string ld = "g++";
#endif
	string runtime = " -L";
	runtime += PathGetter::getEliteHome();
	runtime += "/runtime/";
	runtime += " -L";
	runtime += PathGetter::getEliteHome();
	runtime += "/extlib/lib/";
	string args = runtime + " -o " + fileout + " " + filein + link_args + " -lruntime -ldyncall_s";
	ld += args;
	printf("ld: %s\n", ld.c_str());
	return system(ld.c_str());
}
