/* 
* @Author: sxf
* @Date:   2015-12-11 18:42:32
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 11:28:05
*/


#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

/**
 * @brief 文件遍历的接口
 */
class IFileTraversal {
public:
	virtual void Work(const std::string& now_path, 
			  const std::string& filename, 
			  const std::string& suffix) = 0;
};

/**
 * @brief 跨平台的文件系统接口
 */
class FileUtils
{
public:
	static int create_directory(const std::string& path, bool IgnoreExisting=true);
	static bool isNeedUpdate(const std::string& cfg_path, const std::string& save_path);
	static bool test_dir(const std::string& path);
	static bool test_file(const std::string& path);
	static std::string get_current_path();

	enum traversal_type {
		all, only_file, only_dir
	};

	static int dir_traversal(const std::string& path, IFileTraversal& ifile, traversal_type t);
	static int dir_recursive_traversal(const std::string& path, IFileTraversal& ifile, traversal_type t);
};



#endif // FILE_UTILS_H
