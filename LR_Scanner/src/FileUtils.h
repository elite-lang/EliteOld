/* 
* @Author: sxf
* @Date:   2015-12-11 18:42:32
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-11 20:12:55
*/


#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

class FileUtils
{
public:
	static bool isNeedUpdate(const std::string& cfg_path, const std::string& save_path);

};



#endif // FILE_UTILS_H
