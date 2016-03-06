/*
* @Author: sxf
* @Date:   2015-11-08 09:17:30
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 08:23:22
*/

#ifndef PATH_SET_H
#define PATH_SET_H

#include <vector>
#include <string>

class PathSet_private;

/**
 * @brief 搜索路径集合
 */
class PathSet
{
public:
	PathSet();
	~PathSet();

	void AddPath(const std::string& path);
	const std::string& FindFile(const std::string& filename);
	void FindPackage(const std::string& package);
protected:
	std::vector<std::string> paths;
	PathSet_private* priv;
};


#endif // PATH_SET_H
