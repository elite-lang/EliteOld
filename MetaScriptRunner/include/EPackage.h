/* 
* @Author: sxf
* @Date:   2015-12-24 15:55:11
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 17:20:18
*/

#ifndef E_PACKAGE_H
#define E_PACKAGE_H

#include <string>
#include <map>

using namespace std;

class EPackage
{
public:
	EPackage(const string& json_data);
	~EPackage();

	const string& getName();
	const string& getVersion();

	void Load();
	const string& getProp(const string& name);
private:
	map<string, string> props;
	string str_null;
};



#endif // E_PACKAGE_H
