/* 
* @Author: 笑凡
* @Date:   2014-12-31 08:38:50
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-10 19:42:51
*/

#include<vector>
#include <set>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

#include "BNF.h"
#include "State.h"


class Item
{
public:
    Item();
    Item(const Item& other);
    ~Item();
    bool operator<(const Item& other) const;
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const;
    Item& operator++() { if (itempoint < bnf->getBNFdata().size()) ++itempoint; return *this; }

    // 通过BNF产生项
    Item(BNF* _bnf,int _itempoint);
    void setItem(BNF* _bnf,int _itempoint);
    void addLookahead(int p) { lookahead.insert(p); }
    void setLookahead(set<int> pset) { lookahead = pset; }
    void removeLookahead(int p) { lookahead.erase(p); }
    const set<int>& getLookahead() const { return lookahead; }
    int getNowID() const { // 静态的Item项要保障不能被成员函数修改，故为静态
        if (itempoint >= bnf->getBNFdata().size()) return -1;
        State* s = bnf->getBNFdata().at(itempoint);
        return s->id;
    }
    bool isNULL() const { return bnf == NULL; }
    int getSize() const { return bnf->getBNFdata().size(); }
    const BNF* getBNF() const { return bnf; }
    int getItempoint() const { return itempoint; }
private:
    int itempoint;
    BNF* bnf;
    set<int> lookahead;
};

#endif // ITEM_H
