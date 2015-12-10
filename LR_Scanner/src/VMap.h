#include <map>

using namespace std;

#ifndef VMAP_H
#define VMAP_H

struct VMap {
    map<string, int> VnMap; // 用来处理非终结符
    map<string, int> VtMap; // 用来处理终结符
    map<string, int> ConstMap; // 用来处理静态终结符
    int constSize = 0;
    int constMax = 0;
    int InsertVn(const char* s) {
        auto i = VnMap.find(s);
        if (i != VnMap.end()) return i->second;
        VnMap[s] = ++constSize;
        return constSize;
    }
    int getVn(const char* s){
        return VnMap[s];
    }
    
    void InsertVt(const char* s, int id) {
        VtMap[s] = id;
    }
    int getVt(const char* s){
        if (VtMap.find(s) == VtMap.end()) return -1;
        return VtMap[s];
    }
    
    int InsertConst(const char* s) {
        auto i = ConstMap.find(s);
        if (i != ConstMap.end()) return i->second;
        ConstMap[s] = ++constSize;
        return constSize;
    }
    int getConst(const char* s){
        if (s == NULL) return -1;
        if (ConstMap.find(s) == ConstMap.end()) return -1;
        return ConstMap[s];
    }
    
    void print(map<string,int>& V){
        for (auto p = V.begin(); p != V.end(); ++p)
        {
            pair<string, int> t = *p;
            printf(t.first.c_str());
            printf(":");
            printf("%d\n",t.second);
        }
    }
    void printAll() {
        printf("==== Vn ====");
        print(VnMap);
        printf("==== Vt ====");
        print(VtMap);
        printf("==== Const ====");
        print(ConstMap);
    }
    

    // from Vn id to Vn index in the vector
    int VnIDtoIndex(int p) { if (p<=constMax) return -1;  return p-constMax-1; }

};

#endif
