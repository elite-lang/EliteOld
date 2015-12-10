/* 
* @Author: sxf
* @Date:   2015-11-08 09:17:30
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-12 12:05:50
*/

#ifndef PATH_SET_H
#define PATH_SET_H

#include <vector>
#include <string>

class PathSet_private;
class PathSet
{
public:
	PathSet();
	~PathSet();
	
	void AddPath(std::string path);
	std::string FindFile(std::string filename);
	void FindPackage(std::string package);
protected:
	std::vector<std::string> paths;
	PathSet_private* priv;
};


#endif // PATH_SET_H
