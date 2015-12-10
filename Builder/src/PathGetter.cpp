/* 
* @Author: sxf
* @Date:   2015-11-08 11:16:04
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-10 11:00:06
*/

#include <stdlib.h>
#include "PathGetter.h"
#include <glibmm.h>
#include <unistd.h>  

class PathGetter_Private {
public:
	void setPath();
	Glib::ustring elite_home;
	Glib::ustring elite_lib_path;
	Glib::ustring elite_cfg_path;
	Glib::ustring elite_lex_path;
	Glib::ustring elite_parser_path;
	Glib::ustring elite_now_path;
};



const char* PathGetter::getEliteHome() {
	return getInstance()->elite_home.c_str();
}

const char* PathGetter::getEliteLibPath() {
	return getInstance()->elite_lib_path.c_str();
}

const char* PathGetter::getEliteCfgPath() {
	return getInstance()->elite_cfg_path.c_str();
}

const char* PathGetter::getDefaultLexCfg() {
	return getInstance()->elite_lex_path.c_str();
}

const char* PathGetter::getDefaultParserCfg() {
	return getInstance()->elite_parser_path.c_str();
}

const char* PathGetter::getNowPath() {
	return getInstance()->elite_now_path.c_str();
}

PathGetter_Private* PathGetter::getInstance() {
	if (instance == NULL) {
		instance = new PathGetter_Private();
		instance->setPath();
	}
	return instance;
}

void PathGetter_Private::setPath() {
	const char* home_path = getenv("ELITE_HOME");
	if (home_path == NULL) {
		printf("ELITE_HOME 环境变量未配置\n");
		exit(1);
	}
	elite_home = home_path;
	if (!Glib::file_test(elite_home, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_DIR)) {
		printf("ELITE_HOME 环境变量配置错误: %s 路径不存在\n", elite_home.c_str());
		exit(1);
	}
	elite_lib_path = elite_home;
	elite_cfg_path = elite_home;
	elite_lib_path.append("/libs");
	elite_cfg_path.append("/conf");
	if (!Glib::file_test(elite_lib_path, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_DIR)) {
		printf("%s 目录找不到\n", elite_lib_path.c_str());
		exit(1);
	}
	if (!Glib::file_test(elite_cfg_path, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_DIR)) {
		printf("%s 目录找不到\n", elite_cfg_path.c_str());
		exit(1);
	}

	elite_lex_path = elite_cfg_path;
	elite_parser_path = elite_cfg_path;
	elite_lex_path.append("/lex.cfg");
	elite_parser_path.append("/parser.cfg");
	elite_now_path = getcwd(NULL,0); 
	if (!Glib::file_test(elite_lex_path, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_REGULAR)) {
		printf("%s 文件找不到\n", elite_lex_path.c_str());
		exit(1);
	}
	if (!Glib::file_test(elite_parser_path, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_REGULAR)) {
		printf("%s 目录找不到\n", elite_parser_path.c_str());
		exit(1);
	}
}

bool PathGetter::testFile(const char* file) {
	Glib::ustring filepath = file;
	if (!Glib::file_test(filepath, Glib::FILE_TEST_EXISTS | Glib::FILE_TEST_IS_REGULAR) ) {
		printf("%s 文件找不到\n", file);
		return false;
	}
	return true;
}

PathGetter::PathGetter() {
}

PathGetter::~PathGetter() {
}

PathGetter_Private* PathGetter::instance = NULL;