/* 
* @Author: sxf
* @Date:   2015-11-02 20:13:16
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 12:38:29
*/

#include <iostream>
#include "Builder.h"
#include "Worker.h"
#include "PathGetter.h"
#include <string>
#include "help.h"
using namespace std;

const char* safe_getNext(int argc, const char *argv[], int& i) {
	if (++i < argc) {
		return argv[i];
	} else {
		printf("缺少正确的参数\n");
		exit(0);
	}
}

int is_show_time = 0;

const char* cscw = "-s参数不能和-i参数同时使用, 请选其一指定单独编译或编译文件夹\n";

int main(int argc, const char *argv[])
{
    string nowdir = PathGetter::getNowPath();
	string dir = "build"; // 默认构建位置，当前目录下新建build
	string srcdir = "src"; // 默认源文件目录
	string onlyfile; // 单独只构建一个文件
	string defalut_lex = PathGetter::getDefaultLexCfg();
	string defalut_parser = PathGetter::getDefaultParserCfg();
	int only_one_file = -1;
	int close_link = 0;
	if (argc <= 1) printf(help_message);
	else {
		int i = 0;
		while (i < argc-1) {
			++i;
			string opt(argv[i]);
			if (opt == "-h" || opt == "--help") {
				printf(help_message);
				exit(0);
			}
			if (opt == "-d" || opt == "--dir") {
				dir = safe_getNext(argc, argv, i);
				continue;
			}
			if (opt == "--show") {
				is_show_time = 1; continue;
			}
			if (opt == "-c") {
				close_link = 1; continue;
			}
			if (opt == "-s" || opt == "--src") {
				if (only_one_file == 1) {
					printf(cscw);
					exit(0);
				}
				srcdir = safe_getNext(argc, argv, i);
				only_one_file = 0;
				continue;
			}
			if (opt == "-i" || opt == "--in") {
				if (only_one_file == 0) {
					printf(cscw);
					exit(0);
				}
				onlyfile = safe_getNext(argc, argv, i);
				only_one_file = 1; continue;
			}
			if (opt == "-p" || opt == "--parser") {
				string parser = safe_getNext(argc, argv, i);
				defalut_parser = nowdir + parser;	
			}
			if (opt == "-l" || opt == "--lex") {
				string lex = safe_getNext(argc, argv, i);
				defalut_lex = nowdir + lex;
			}
		}
		if (only_one_file == -1)
			only_one_file = 0;

		// 创建Worker和Builder
		Worker* worker = Worker::CreateDefault(
			defalut_lex.c_str(), defalut_parser.c_str());
		Builder* builder = Builder::Create(worker);
		builder->SetBuildPath(dir);
		if (is_show_time == 1)
			builder->setDebugFilePath(dir.c_str());
		if (only_one_file == 1) {
			builder->BuildFile(onlyfile);
		} else {
			builder->BuildPath(srcdir);
		}
		builder->Close();
	}
	return 0;
}
