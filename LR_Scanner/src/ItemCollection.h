/* 
* @Author: sxf
* @Date:   2014-12-31 09:05:37
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-01 19:42:16
*/

#include <set>
#include <vector>
#include "Item.h"
#include "BNF.h"

using namespace std;

#ifndef ITEM_COLLECTION_H
#define ITEM_COLLECTION_H

class ItemCollection
{
public:
    ItemCollection();
    ~ItemCollection();
    ItemCollection(set<Item> I);
    ItemCollection(const ItemCollection& other);
    ItemCollection& operator=(const ItemCollection& other);
    bool operator==(const ItemCollection& other);
    
    static vector<ItemCollection*> MakeLR0Items(VMap*,BNF*,const vector<BNF*>&);
    static void MakeLALRItems(vector<ItemCollection*>&,const vector<BNF*>&);
    static vector<Item> findItems(int,const vector<BNF*>&);

    
    // 计算GOTO函数
    ItemCollection* GOTO(int p) const { return GotoMap[p]; }

    void printSet();
    void printSpread();
    // ===== setter and getter =====
    void setVmap(VMap* _v) { vmap = _v; GotoMap.resize(_v->constSize+1,0); }
    void setID(int _id) { id = _id; }
    int getID() { return id; }
    void setGOTO(int p, ItemCollection* i) { GotoMap[p] = i; }
    void addCoreItems(Item i) { CoreItems.insert(i); }
    bool isNull() const { return CoreItems.empty(); }
    set<Item>& getCoreItems() { return CoreItems; }
    set<Item>& getItems() { return Items; }
    void ClearItems() { Items.clear(); } // Clean the Items which isn't Core Items
private:
    int id; // the id of ItemCollection, means state

    static VMap* vmap;

    set<Item> CoreItems; // it the core item
    set<Item> Items; // other item
    vector<ItemCollection*> GotoMap; // int a = GotoMap[s]  s is in the V*, a is the next state
    map<Item,vector<pair<ItemCollection*,Item>>> SpreadMap; // 从某项到某项的传播，已本集合的内核项为Key

    static vector<bool> NULLABLE;
    static vector<set<int>> FirstMap;
    static vector<bool> ifFirstFinded;

    // 构建LR(0)项集族
    void CLOSURE0(const vector<BNF*>&);

    // 构建LR(1)项集族，由于自身此时已经有内核项，不必再传入其他参数
    void CLOSURE1(const vector<BNF*>& bnfs);

    static void MakeNULLANDFRIST(const vector<BNF*>& bnfs);

    // 计算Nullable函数
    static void MakeNULLABLE(vector<bool>& NULLABLE,const vector<BNF*>& bnfs);
    // 计算First集合
    static set<int> FIRST(int id, const vector<BNF*>& bnfs);
    static set<int> FIRST(vector<int>& Vlist,const set<int> lookahead, const vector<BNF*>& bnfs);

    // 确定传播表和自发生成的符号
    void MakeSpreadMap(Item& A,set<Item>& other_core_items);

    // 计算Lookahead符号
    void MakeLookahead(const Item& item,const vector<BNF*>& bnfs);

    // 计算GOTO函数, 如果指针列表中有相同的项集族，则直接返回该项，不重新建
    // 如果没有找到，则返回重新建立的项集族，并将该项集族添加到列表中的末尾
    ItemCollection* MakeGOTO(int x,vector<ItemCollection*>&);
    // 计算Goto函数时，对每一个内核项构建对应的ItemCollection
    static void MakeItemCollection(int x,set<Item>& itemset, ItemCollection& items);
};


#endif // ITEM_COLLECTION_H
