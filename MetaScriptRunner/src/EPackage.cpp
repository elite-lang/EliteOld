/* 
* @Author: sxf
* @Date:   2015-12-24 17:15:29
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-26 19:12:39
*/

#include "EPackage.h"
#include "cJSON.h"
#include "FileUtils.h"
#include "PathUtils.h"
#include "MetaScriptRunner.h"
#include "PackageJIT.h"
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
}

EPackage::~EPackage() {

}

void EPackage::Load() {
	cout << "Load Package: " << base_path << endl;
	FileTraversal ft(msr, *this);
	FileUtils::dir_traversal(base_path, ft, FileUtils::only_file);
}

const string& EPackage::getName() {
	return getProp("name");
}

const string& EPackage::getVersion() {
	return getProp("version");
}

bool EPackage::isDefaultLoad() {
	return getProp("default_load") == "true";
}
bool EPackage::isLoaded() {
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

string EPackage::str_null;