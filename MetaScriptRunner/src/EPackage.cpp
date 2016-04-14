/*
* @Author: sxf
* @Date:   2015-12-24 17:15:29
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 15:48:30
*/

#include "EPackage.h"
#include "cJSON.h"
#include "FileUtils.h"
#include "PathUtils.h"
#include "MetaScriptRunner.h"
#include "PackageJIT.h"
#include "Builder.h"
#include <iostream>
using namespace std;

class FileTraversal : public IFileTraversal {
public:
	FileTraversal(MetaScriptRunner* msr, EPackage& epkg)
		: epkg(epkg) {
		this->msr = msr;
	}

	virtual void Work(const std::string& now_path,
			  const std::string& filename,
			  const std::string& suffix)
	{
		string filepath = now_path + "/" + filename;
		if (suffix == ".lua") {
			msr->run_file(filepath);
		}
		if (suffix == ".epbc") {
			PackageJIT::LoadPlugin(filepath, epkg.getName(), msr);
		}
	}
	MetaScriptRunner* msr;
	EPackage& epkg;
};


EPackage::EPackage(const string& path, MetaScriptRunner* msr) {
	this->msr = msr;
	base_path = path;
	string json_path = PathUtils::native(base_path+"/package.json");
	string json_data = FileUtils::fileReader(json_path.c_str());
	loadJson(json_data);
	addRuntimePath();
}

EPackage::~EPackage() {

}

void EPackage::Load() {
	cout << "Load Package: " << base_path << endl;
	FileTraversal ft(msr, *this);
	FileUtils::dir_traversal(base_path, ft, FileUtils::only_file);
	string link_args = getRuntime();
	if (link_args != str_null) // 添加runtime链接参数
		msr->getBuilder()->AddLinkArgs(link_args);
	insertProp("package_loaded", "true");
}


void EPackage::Run() {
	PackageJIT::RunPlugin(getName(), msr);
}

const bool EPackage::canLoadOnPlatform() {
	string platform = getProp("platform");
	if (platform.empty()) return true;
#if defined(_WIN32)
	return platform == "win32";
#elif defined(__linux__)
	return platform == "linux";
#elif defined(__APPLE__)
	return platform == "apple";
#endif
	return false;
}

const string& EPackage::getName() {
	return getProp("name");
}

const string& EPackage::getVersion() {
	return getProp("version");
}

const string& EPackage::getRuntime() {
	return getProp("runtime");
}

const bool EPackage::isDefaultLoad() {
	return getProp("default_load") == "true";
}
const bool EPackage::isLoaded() {
	return getProp("package_loaded") == "true";
}

const string& EPackage::getProp(const string& name) {
	auto p = props.find(name);
	if (p != props.end()) return p->second;
	return str_null;
}

void EPackage::insertProp(const string& name, const string& value) {
	props[name] = value;
}

void EPackage::loadJson(const string& json) {
	cJSON* cj = cJSON_Parse(json.c_str());
	if (!cj) { printf("error json format\n"); return; }

	for ( cJSON* p = cj->child; p != NULL; p = p->next )
		if ( p->type == cJSON_String )
			insertProp(p->string, p->valuestring);

	cJSON_Delete(cj);
}

void EPackage::addRuntimePath() {
	string args = getRuntime();
	if (args == str_null) return;
	string Lpath = "-L";
	Lpath += base_path;
	Lpath += ' ';
	Lpath += args;
	insertProp("runtime", Lpath);
}


string EPackage::str_null;
