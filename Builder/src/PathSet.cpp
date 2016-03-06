/*
* @Author: sxf
* @Date:   2015-11-12 10:11:38
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-12 10:11:45
*/

#include "PathSet.h"
#include "PathUtils.h"
#include "FileUtils.h"
#include "PackageChanger.hpp"

#include <string>
using namespace std;

class file_searcher : public IFileTraversal {
public:
    file_searcher(const string& name) {
        file = name;
    }

	virtual void Work(const string& now_path,
			  const string& filename,
			  const string& suffix) {

        if (file == (filename + "." + suffix)) {
            ans = now_path + "/" + file;
        }
    }
    string ans;
private:
    string file;
};


PathSet::PathSet() {

}

PathSet::~PathSet() {

}


void PathSet::AddPath(const std::string& path) {
    paths.push_back(path);
}

std::string PathSet::FindFile(const std::string& filename) {
    file_searcher fs(filename);
    for (auto& item : paths) {
        FileUtils::dir_traversal(item, fs, FileUtils::only_file);
        if (fs.ans.empty() == false) return fs.ans;
    }
    return string();
}

std::vector<std::string> PathSet::FindPackage(const std::string& package) {
    std::vector<std::string> package_list;
    string path = PackageChanger::pname2path(package);
    for (auto& item : paths) {
        string p = item + "/" + path;
        p = PathUtils::native(p);
        if (FileUtils::test_dir(p)) {
    		package_list.push_back(p);
    	}
    }
    return package_list;
}


std::vector<std::string> PathSet::FindAllPackageName() {

}
