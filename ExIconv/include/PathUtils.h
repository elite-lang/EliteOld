/*
* @Author: sxf
* @Date:   2015-12-20 11:38:17
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-20 11:58:04
*/


#ifndef PATH_UTILS_H
#define PATH_UTILS_H

#include <string>

/**
 * @brief 跨平台的路径拼接工具类
 */
class PathUtils
{
public:
	static std::string native(const std::string& path);
	static std::string parent_path(const std::string& path);
};


#endif // PATH_UTILS_H
