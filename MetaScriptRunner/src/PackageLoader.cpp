/* 
* @Author: sxf
* @Date:   2015-12-24 17:21:09
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 11:31:20
*/

#include "PackageLoader.h"
#include "FileUtils.h"
#include <iostream>
using namespace std;

class DirFileTraversal : public IFileTraversal {
public:
	virtual void Work(const std::string& now_path, 
			  const std::string& filename, 
			  const std::string& suffix) 
	{
		cout << now_path + "/" + filename << endl;
	}
};



PackageLoader::PackageLoader(const string& base_path) {
	this->base_path = base_path;
}

PackageLoader::~PackageLoader() {

}


/**
 * @brief 找出目录下所以的可加载项
 */	
void PackageLoader::FindAll() {
	cout << "begin FindAll: " << base_path <<endl;
	DirFileTraversal dft;
	FileUtils::dir_traversal(base_path, dft, FileUtils::only_dir);
}


/**
 * @brief 加载全部默认需要加载的包
 */
void PackageLoader::LoadDefault() {
	for (auto& p : packages) {
		auto pkg = p.second;
		if (pkg->isDefaultLoad())
			pkg->Load();
	}
} 
