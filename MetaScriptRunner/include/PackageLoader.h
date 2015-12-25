/* 
* @Author: sxf
* @Date:   2015-12-24 15:48:44
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 15:24:35
*/

#ifndef PACKAGE_LOADER_H
#define PACKAGE_LOADER_H

#include "EPackage.h"

class MetaScriptRunner;

/**
 * @brief 扩展包加载器
 */
class PackageLoader
{
public:
	PackageLoader(const string& base_path, MetaScriptRunner* msr);
	~PackageLoader();

	/**
	 * @brief 找出目录下所以的可加载项
	 */	
	void FindAll();

	/**
	 * @brief 加载全部默认需要加载的包
	 */
	void LoadDefault(); 

private:
	string base_path;
	map<string, EPackage*> packages;

	MetaScriptRunner* msr;
};


#endif // PACKAGE_LOADER_H
