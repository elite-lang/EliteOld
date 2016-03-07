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

	/**
	 * 添加一个路径
	 * @method AddPath
	 * @param  path    要添加的目录(绝对路径)
	 */
	void AddPath(const std::string& path);

	/**
	 * 查找一个文件在该路径集合中的位置
	 * @method FindFile
	 * @param  filename 文件名
	 * @return          第一个找到的文件的绝对路径
	 */
	std::string FindFile(const std::string& filename);

	/**
	 * 查找一个包的全部位置
	 * @method FindPackage
	 * @param  package 包名
	 * @return         返回全部找到的包的绝对路径
	 */
	std::vector<std::string> FindPackage(const std::string& package);

	/**
	 * 查找目录中全部的包
	 * @method FindAllPackageName
	 * @return         返回全部找到的包的名字
	 */
	std::vector<std::string> FindAllPackageName();

	const std::vector<std::string>& getPaths() { return paths; }
protected:
	std::vector<std::string> paths;
	PathSet_private* priv;
};


#endif // PATH_SET_H
