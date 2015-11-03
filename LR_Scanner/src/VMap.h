#include "afx.h"
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
    int InsertVn(const BNFCHAR* s) {
        auto i = VnMap.find(s);
        if (i != VnMap.end()) return i->second;
        VnMap[s] = ++constSize;
        return constSize;
    }
    int getVn(const BNFCHAR* s){
        return VnMap[s];
    }
    
    void InsertVt(const BNFCHAR* s, int id) {
        VtMap[s] = id;
    }
    int getVt(BNFCHAR* s){
        return VtMap[s];
    }
    
    int InsertConst(const BNFCHAR* s) {
        auto i = ConstMap.find(s);
        if (i != ConstMap.end()) return i->second;
        ConstMap[s] = ++constSize;
        return constSize;
    }
    int getConst(BNFCHAR* s){
        if (ConstMap.find(s) == ConstMap.end()) return -1;
        return ConstMap[s];
    }
    
    void print(map<string,int>& V){
        for (auto p = V.begin(); p != V.end(); ++p)
        {
            pair<string, int> t = *p;
            printf(t.first.c_str());
            Print(_T(":"));
            printf("%d\n",t.second);
        }
    }
    void printAll() {
        println(_T("==== Vn ===="));
        print(VnMap);
        println(_T("==== Vt ===="));
        print(VtMap);
        println(_T("==== Const ===="));
        print(ConstMap);
    }
    

    // from Vn id to Vn index in the vector
    int VnIDtoIndex(int p) { if (p<=constMax) return -1;  return p-constMax-1; }

};

#endif
