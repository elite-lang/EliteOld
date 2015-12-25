/* 
* @Author: sxf
* @Date:   2015-12-24 17:15:29
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 12:56:14
*/

#include "EPackage.h"
#include "cJSON.h"
#include "FileUtils.h"
#include <iostream>
using namespace std;

class FileTraversal : public IFileTraversal {
public:
	virtual void Work(const std::string& now_path, 
			  const std::string& filename, 
			  const std::string& suffix) 
	{
		cout << now_path + "/" + filename << endl;
	}
};


EPackage::EPackage(const string& json_data) {
	loadJson(json_data);
}

EPackage::~EPackage() {

}

void EPackage::Load() {

}

const string& EPackage::getName() {
	return getProp("name");
}

const string& EPackage::getVersion() {
	return getProp("version");
}

bool EPackage::isDefaultLoad() {
	return getProp("default_load") != "true";
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

	for ( cJSON* p = cj; p != NULL; p = p->next ) 
		if ( p->type == cJSON_String ) 
			insertProp(p->string, p->valuestring);

	cJSON_Delete(cj);
}