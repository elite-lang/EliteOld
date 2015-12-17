/* 
* @Author: sxf
* @Date:   2015-12-11 18:42:32
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-17 20:34:59
*/


#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

class FileUtils
{
public:
	static bool isNeedUpdate(const std::string& cfg_path, const std::string& save_path);
	static bool test_dir(const std::string& path);
	static bool test_file(const std::string& path);
};



#endif // FILE_UTILS_H
