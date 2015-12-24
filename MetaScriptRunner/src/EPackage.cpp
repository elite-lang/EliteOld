/* 
* @Author: sxf
* @Date:   2015-12-24 17:15:29
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 17:20:17
*/

#include "EPackage.h"
#include "cJSON.h"

EPackage::EPackage(const string& json_data) {
	
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

const string& EPackage::getProp(const string& name) {
	auto p = props.find(name);
	if (p != props.end()) return p->second;
	return str_null;
}
