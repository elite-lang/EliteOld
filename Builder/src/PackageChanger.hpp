#ifndef PACKAGE_CHANGER_H
#define PACKAGE_CHANGER_H

#include <string>

class PackageChanger {
public:
    static std::string pname2path(const std::string& name) {
        std::string str = name;
        for (auto& i : str) {
            if (i == '.') i = '/';
        }
        return str;
    }

    static std::string path2pname(const std::string& path) {
        std::string str = path;
        if (*(str.begin()) == '/') str.erase(str.begin());
        if (*(str.rbegin()) == '/') str.erase(--str.end());
        for (auto& i : str) {
            if (i == '/') i = '.';
        }
        return str;
    }
};



#endif /* end of include guard: PACKAGE_CHANGER_H */
