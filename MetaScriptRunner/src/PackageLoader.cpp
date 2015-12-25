/* 
* @Author: sxf
* @Date:   2015-12-24 17:21:09
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 10:43:00
*/

#include "PackageLoader.h"
#include "FileUtils.h"
#include <iostream>

class DirFileTraversal : public IFileTraversal {
public:
	virtual void Work(const std::string& now_path, 
			  const std::string& filename, 
			  const std::string& suffix) 
	{
		cout << now_path + "/" + filename + "." + suffix << endl;
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
	DirFileTraversal dft;
	FileUtils::dir_recursive_traversal(base_path, dft);
}


/**
 * @brief 加载全部默认需要加载的包
 */
void PackageLoader::LoadDefault() {

} 
