/* 
* @Author: sxf
* @Date:   2015-11-08 11:16:04
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 13:32:35
*/

#include <stdlib.h>
#include "PathGetter.h"
#include <glibmm.h>

string& PathGetter::getEliteHome() {
	return getInstance()->elite_home;
}

string& PathGetter::getEliteLibPath() {
	return getInstance()->elite_lib_path;
}

string& PathGetter::getEliteCfgPath() {
	return getInstance()->elite_cfg_path;
}

PathGetter* PathGetter::getInstance() {
	if (instance == NULL) {
		instance = new PathGetter();
		instance->setPath();
	}
	return instance;
}

void PathGetter::setPath() {
	Glib::ustring pathvar;
	pathvar = getenv("ELITE_HOME");
	printf("pathvar=%s",pathvar.c_str());
	// elite_home = pathvar;
	if (!Glib::file_test(pathvar, Glib::FILE_TEST_IS_DIR)) {
		printf("ELITE_HOME 环境变量配置错误\n");
	}
	// pathvar.append("/libs");
	// pathvar.append("/conf");
}

PathGetter::PathGetter() {
}

PathGetter::~PathGetter() {
}

PathGetter* PathGetter::instance = NULL;