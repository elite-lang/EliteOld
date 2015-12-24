/* 
* @Author: sxf
* @Date:   2015-12-24 15:48:44
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 16:36:16
*/

#ifndef PACKAGE_LOADER_H
#define PACKAGE_LOADER_H

#include "EPackage.h"


class PackageLoader
{
public:
	PackageLoader(const string& base_path);
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
};


#endif // PACKAGE_LOADER_H
