/* 
* @Author: sxf
* @Date:   2015-11-08 11:08:05
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 11:26:27
*/

#ifndef PATH_GETTER_H
#define PATH_GETTER_H

#include <string>
using namespace std;

class PathGetter
{
public:
	static string& getEliteHome();
	static string& getEliteLibPath();
	static string& getEliteCfgPath();
	static PathGetter* getInstance();
private:
	PathGetter();
	~PathGetter();
	void setPath();

	string elite_home;
	string elite_lib_path;
	string elite_cfg_path;

	static PathGetter* instance;
};



#endif // PATH_GETTER_H
