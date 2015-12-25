/* 
* @Author: sxf
* @Date:   2015-12-24 17:21:09
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 18:37:44
*/

#include "PackageLoader.h"
#include "FileUtils.h"
#include "PathUtils.h"
#include "MetaScriptRunner.h"
#include <iostream>
using namespace std;

class DirFileTraversal : public IFileTraversal {
public:
	DirFileTraversal(map<string, EPackage*>& pkgs, MetaScriptRunner* msr)
		: packages(pkgs)
	{
		this->msr = msr;
	}

	virtual void Work(const std::string& now_path, 
			  const std::string& filename, 
			  const std::string& suffix) 
	{
		string cfg_path = PathUtils::native(now_path+"/"+filename+"/package.json");
		if (!FileUtils::test_file(cfg_path)) return;
		string path = PathUtils::native(now_path+"/"+filename);
		EPackage* pkg = new EPackage(path, msr);
		string name = pkg->getName();
		if (name == EPackage::str_null) { delete pkg; return; }
		packages[name] = pkg;
	}

	map<string, EPackage*>& packages;
	MetaScriptRunner* msr;
};



PackageLoader::PackageLoader(const string& base_path, MetaScriptRunner* msr) {
	this->base_path = base_path;
	this->msr = msr;
}

PackageLoader::~PackageLoader() {

}


/**
 * @brief 找出目录下所以的可加载项
 */	
void PackageLoader::FindAll() {
	DirFileTraversal dft(packages, msr);
	FileUtils::dir_traversal(base_path, dft, FileUtils::only_dir);
}


/**
 * @brief 加载全部默认需要加载的包
 */
void PackageLoader::LoadDefault() {
	for (auto& p : packages) {
		auto pkg = p.second;
		if (pkg->isDefaultLoad() && !pkg->isLoaded())
			pkg->Load();
	}
} 
