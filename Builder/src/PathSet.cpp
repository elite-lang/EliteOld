/*
* @Author: sxf
* @Date:   2015-11-12 10:11:38
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-12 10:11:45
*/

#include "PathSet.h"

PathSet::PathSet() {

}

PathSet::~PathSet() {

}


void PathSet::AddPath(const std::string& path) {
    paths.push_back(path);
}

const std::string& PathSet::FindFile(const std::string& filename) {
    for (auto item : paths) {
        
    }
}

void PathSet::FindPackage(const std::string& package) {

}
