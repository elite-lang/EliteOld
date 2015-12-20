/* 
* @Author: sxf
* @Date:   2015-12-11 18:48:19
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-20 22:47:34
*/

#include "FileUtils.h"
#include <iostream>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TimeValue.h>
#include <llvm/Support/Path.h>
#include <llvm/ADT/SmallVector.h>
using namespace std;
using namespace llvm::sys;
using namespace llvm::sys::fs;

int FileUtils::create_directory(const std::string& path, bool IgnoreExisting) {
	llvm::sys::fs::create_directory(path, IgnoreExisting);
	return 0;
}

bool FileUtils::isNeedUpdate(const std::string& cfg_path, const std::string& save_path) {
	file_status save_file_status;
	status (save_path, save_file_status);
	if (!exists(save_file_status)) {
		printf("\n\n%s\n##### 文件不存在\n\n\n", save_path.c_str());
		return true;
	}
	file_status cfg_file_status;
	status (cfg_path, cfg_file_status);
	if (!exists(cfg_file_status)) {
		printf("\n\n%s\n##### 文件不存在\n\n\n", cfg_path.c_str());
		return true;
	}
	TimeValue save_time = save_file_status.getLastModificationTime();
	TimeValue cfg_time  = cfg_file_status.getLastModificationTime();
	
	if (save_time > cfg_time) return false;
	else {
		printf("\n\n##### 时间不正确\n\n\n");
		return true;
	}
}

bool FileUtils::test_dir(const std::string& path) {
	file_status file_status;
	status (path, file_status);
	return exists(file_status) && is_directory(file_status);
}

bool FileUtils::test_file(const std::string& path) {
	file_status file_status;
	status (path, file_status);
	return exists(file_status) && is_regular_file(file_status);
}

string FileUtils::get_current_path() {
	llvm::SmallVector< char, 128 > result;
	current_path(result);
	result.append(1, (char)0);
	return result.data();
}

int FileUtils::dir_traversal(const std::string& path, IFileTraversal& ifile) {
	std::error_code ec;
	directory_iterator di(path, ec);
	directory_iterator end;
	while (di != end) {
		auto entry = *di;
		if (is_regular_file(entry.path())) {
			ifile.Work(
				llvm::sys::path::parent_path(entry.path()).str(),
				llvm::sys::path::filename(entry.path()).str(),
				llvm::sys::path::extension(entry.path()).str()
				);
		}
		di.increment(ec);
	}
	return 0;
}

int FileUtils::dir_recursive_traversal(const std::string& path, IFileTraversal& ifile) {
	return 0;
}
