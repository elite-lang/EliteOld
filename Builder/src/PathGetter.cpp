/* 
* @Author: sxf
* @Date:   2015-11-08 11:16:04
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 10:24:30
*/

#include <stdlib.h>
#include "PathGetter.h"
#include "FileUtils.h"
#include "PathUtils.h"
#include "elite_tools.h"

class PathGetter_Private {
public:
	void setPath();
	string elite_home;
	string elite_lib_path;
	string elite_cfg_path;
	string elite_lex_path;
	string elite_parser_path;
	string elite_now_path;
	string elite_tools_path;
	string elite_packages_path;
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

const char* PathGetter::getEliteToolsPath() {
	return getInstance()->elite_tools_path.c_str();
}

const char* PathGetter::getElitePackagesPath() {
	return getInstance()->elite_packages_path.c_str();
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
	if (!FileUtils::test_dir(elite_home)) {
		printf("ELITE_HOME 环境变量配置错误: %s 路径不存在\n", elite_home.c_str());
		exit(1);
	}
	elite_lib_path = elite_home;
	elite_cfg_path = elite_home;
	elite_tools_path = elite_home;
	elite_lib_path.append("/libs");
	elite_cfg_path.append("/conf");
	elite_packages_path.append("/packages");
	// 本地化
	elite_lib_path = PathUtils::native(elite_lib_path);
	elite_cfg_path = PathUtils::native(elite_cfg_path);

	if (!FileUtils::test_dir(elite_lib_path)) {
		printf("%s 目录找不到\n", elite_lib_path.c_str());
		exit(1);
	}
	if (!FileUtils::test_dir(elite_cfg_path)) {
		printf("%s 目录找不到\n", elite_cfg_path.c_str());
		exit(1);
	}

	elite_tools_path.append(ELITE_TOOLS_PATH);
	// 本地化
	elite_tools_path = PathUtils::native(elite_tools_path);

	if (!FileUtils::test_dir(elite_tools_path)) {
		printf("%s 目录找不到\n", elite_tools_path.c_str());
		exit(1);
	}

	elite_lex_path = elite_cfg_path;
	elite_parser_path = elite_cfg_path;
	elite_lex_path.append("/lex.cfg");
	elite_parser_path.append("/parser.cfg");
	// 本地化
	elite_lex_path = PathUtils::native(elite_lex_path);
	elite_parser_path = PathUtils::native(elite_parser_path);
	elite_now_path = FileUtils::get_current_path();
	if (!FileUtils::test_file(elite_lex_path)) {
		printf("%s 文件找不到\n", elite_lex_path.c_str());
		exit(1);
	}
	if (!FileUtils::test_file(elite_parser_path)) {
		printf("%s 文件找不到\n", elite_parser_path.c_str());
		exit(1);
	}

}

bool PathGetter::testFile(const char* file) {
	string filepath = file;
	if (!FileUtils::test_file(filepath)) {
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