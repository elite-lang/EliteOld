/*
* @Author: sxf
* @Date:   2015-12-20 11:55:34
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-20 12:07:11
*/

#include "PathUtils.h"
#include <llvm/Support/Path.h>
#include <llvm/ADT/SmallVector.h>
using namespace std;
using namespace llvm;
using namespace llvm::sys;

std::string PathUtils::native(const std::string& path) {
	SmallVector<char, 256> result;
	path::native(path, result);
	result.append(1, (char)0);
	return result.data();
}

std::string PathUtils::parent_path(const std::string& path) {
	return path::parent_path(path).str();
}
