/* 
* @Author: sxf
* @Date:   2014-12-31 18:46:08
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-10 12:01:55
*/

#include "ItemCollection.h"
#include <algorithm>
using namespace std;

#ifndef TESTV
#define TESTV -2
#endif


vector<bool> ItemCollection::NULLABLE;
vector<set<int>> ItemCollection::FirstMap;
vector<bool> ItemCollection::ifFirstFinded;
VMap* ItemCollection::vmap;


ItemCollection::ItemCollection(){

}

ItemCollection::~ItemCollection(){

}

ItemCollection::ItemCollection(const ItemCollection& other){
    *this = other;
}

ItemCollection& ItemCollection::operator=(const ItemCollection& other){
    id = other.id; // the id of ItemCollection, means state
    vmap = other.vmap;
    CoreItems = other.CoreItems; // it the core item
    Items = other.Items; // other item
    GotoMap = other.GotoMap;
    SpreadMap = other.SpreadMap;
}

bool ItemCollection::operator==(const ItemCollection& other){
    if (this->CoreItems == other.CoreItems) return true;
    return false;
}

vector<ItemCollection*> ItemCollection::MakeLR0Items(VMap* vmap, BNF* mainbnf,const vector<BNF*>& bnfs){
    vector<ItemCollection*> itemslist; // the queue
    // init the queue
    Item item(mainbnf,0);
    item.addLookahead(0);
    ItemCollection* pItem = new ItemCollection();
    pItem->addCoreItems(item); pItem->setID(0);
    itemslist.push_back(pItem);

    int i = 0;
    while (i < itemslist.size()) {
        ItemCollection* now = itemslist[i];
        now->setVmap(vmap); now->CLOSURE0(bnfs);
        for (int x = 1; x < vmap->constSize; ++x) {
            now->MakeGOTO(x,itemslist);
        }
        now->ClearItems();
        ++i;
    }
    return itemslist;
}


void ItemCollection::MakeSpreadMap(Item& A, set<Item>& other_core_items) {
    for (auto p : other_core_items) {
        Item B(p);
        int id = B.getNowID();
        if (id == -1) continue; // 点在末尾的规约态将不再被考虑，不会传播
        ++B;
        const set<int> lookahead = (p).getLookahead();
        if (lookahead.size() != 0) {
            for (auto q : lookahead) {
                ItemCollection* pItems = GotoMap[id];

                if (q == TESTV) {
                    if (SpreadMap.find(A) == SpreadMap.end())
                        SpreadMap[A] = vector<pair<ItemCollection*,Item>>();
                    auto& Amap = SpreadMap[A];
                    Amap.push_back(make_pair(pItems,B)); // 将每一个项的对应表置为B,用于传播lookahead时的查找
                } else {
                    B.removeLookahead(TESTV);
                    set<Item>& core = pItems->getCoreItems();

                    // 这里要特别小心,如果有从多个地方自发生成了同一个内核项的Lookahead符号
                    // 要对所有的符号求并集,注意自发生成是看转移源的位置,源可能有多个
                    auto r = core.find(B);
                    const Item& oldB = (*r);
                    for (int oldlookahead : oldB.getLookahead())
                        B.addLookahead(oldlookahead);
                    // ======================

                    core.erase(B); core.insert(B); // 更新B的Lookahead符号
                    break;
                }
            }
        }
    }
}

// 本函数的作用时对当前this对象复制一份求向前看操作符的传播方向表
// 同时会确定出自发生成的向前看操作符   item是当前要测试的项，会对其增加不存在的向前看看符号#
void ItemCollection::MakeLookahead(const Item& item,const vector<BNF*>& bnfs){
    Item A(item); set<int> tempset; // 当前遍历到Core中的A符号
    tempset.insert(TESTV);
    A.setLookahead(tempset); // 向这个项中插入测试符号TESTV
    ItemCollection items = *this; // 从自身复制一份测试版
    items.CoreItems.erase(A); items.CoreItems.insert(A); // 更新CoreItems表中的值
    items.CLOSURE1(bnfs); // 对复制版求闭包

    MakeSpreadMap(A,items.getCoreItems());
    MakeSpreadMap(A,items.getItems());
//    //========== for debug ==========

//    printf("TEST_I%d:",items.getID());
//    items.printSet();
}

// 将每一个新的lookahead符号传播到CoreItems里的pItem上去
bool SpreadLookahead(const set<int>& newlookahead, const Item& pItem, set<Item>& CoreItems) {
    Item newItem(pItem); bool needupdata = false;
    auto q = CoreItems.find(pItem);
    if (q != CoreItems.end()) {
        const set<int>& lookaheadset = (*q).getLookahead(); // 取旧的向前看符号集
        newItem.setLookahead(lookaheadset);
        for (auto p = newlookahead.begin(); p != newlookahead.end(); ++p) {
            int lookahead = *p;
            if (lookaheadset.find(lookahead) == lookaheadset.end()) { // 没有找到该符号
                newItem.addLookahead(lookahead);
                needupdata = true;
            }
        }
        if (needupdata) { // 保证更新CoreItems
            CoreItems.erase(pItem); CoreItems.insert(newItem);
        }
    }
    return needupdata;
}

void ItemCollection::MakeLALRItems(vector<ItemCollection*>& LR0Items,const vector<BNF*>& bnfs){
    MakeNULLANDFRIST(bnfs);

    // 确定自发生成的符号和传播关系
    for (ItemCollection* items : LR0Items) {
        set<Item>& Core = items->getCoreItems();
        for (auto q : Core) {
            items->MakeLookahead(q,bnfs);
        }
    }
    // 开始传播过程
    bool b;
    do {
        b = false;
        for (ItemCollection* items : LR0Items) {
            for (const Item& item : items->getCoreItems()) { // 这是要遍历的内核项
                auto m = items->SpreadMap.find(item); //找出该内核项对应的传播表
                if (m != items->SpreadMap.end()) {
                    vector<pair<ItemCollection*,Item>>& imap = m->second;
                    for (auto i = imap.begin(); i != imap.end(); ++i) { // 遍历该传播表
                        ItemCollection* pItems = i->first;
                        const Item& pItem = i->second;
                        if (SpreadLookahead(item.getLookahead(),pItem,pItems->getCoreItems())) b = true;
                    }
                }
            }
        }
    }while(b);
    // 很重要的是，还需要再求一遍闭包，在加上了正确的符号后
    for (auto p = LR0Items.begin(); p != LR0Items.end(); ++p) {
        ItemCollection* items = *p;
        items->CLOSURE1(bnfs);
    }
}

void ItemCollection::MakeItemCollection(int x,set<Item>& itemset, ItemCollection& items) {
    for (auto p = itemset.begin(); p != itemset.end(); ++p ) {
        const Item& now = *p;
        int nowid = now.getNowID();
        if ( nowid == x ) {
            Item t(*p);
            ++t;
            items.addCoreItems(t);
        }
    }
}

// 为当前项目集构建GOTO函数
ItemCollection* ItemCollection::MakeGOTO(int x,vector<ItemCollection*>& itemslist) {
    ItemCollection* tempItems = new ItemCollection();
    MakeItemCollection(x,CoreItems,*tempItems);
    MakeItemCollection(x,Items,*tempItems);
    if (tempItems->isNull()) {
        delete tempItems;
        return NULL;
    }
    for (auto p = itemslist.begin(); p != itemslist.end(); ++p) {
        ItemCollection* pItems = *p;
        if (*pItems == *tempItems) {
            delete tempItems;
            this->setGOTO(x,pItems);
            return pItems;
        }
    }
    tempItems->setID(itemslist.size());
    this->setGOTO(x,tempItems);
    itemslist.push_back(tempItems);
    return tempItems;
}

vector<Item> ItemCollection::findItems(int id,const vector<BNF*>& bnfs) {
    vector<Item> newbnfs;
    if (id <= vmap->constMax) return newbnfs; // if the id is not Vn, don't need to find!
    for (auto p = bnfs.begin(); p != bnfs.end(); ++p) {
        BNF* bnf = *p;
        Item item(bnf,0);
        if (id == bnf->getRoot()->id) newbnfs.push_back(item);
    }
    return newbnfs;
}

void ItemCollection::CLOSURE0(const vector<BNF*>& bnfs){
    vector<Item> itemlist(CoreItems.begin(),CoreItems.end());
    int i = 0;
    while (i < itemlist.size()) {
        Item item = itemlist[i];
        int id = item.getNowID();
        auto itemset = findItems(id,bnfs);
        for (auto p = itemset.begin(); p != itemset.end(); ++p) {
            if (find(itemlist.begin(),itemlist.end(),*p)==itemlist.end()) {
                itemlist.push_back(*p);
                Items.insert(*p);
            }
        }
        ++i;
    }
}

set<int> ItemCollection::FIRST(int id, const vector<BNF*>& bnfs) {

    int index = vmap->VnIDtoIndex(id);
    if (index == -1) { // 终结符直接返回
        set<int> firstset;
        firstset.insert(id); return firstset;
    }
    set<int>& firstset = FirstMap[index];
    if (ifFirstFinded[index]) return firstset;
    ifFirstFinded[index] = true;
    if (NULLABLE[index]) firstset.insert(-3);
    for (Item& i : findItems(id,bnfs)) {
        int nowid = i.getNowID();
        bool b = true;
        while(b && nowid != -1) { // 循环整个项的每个V
            set<int> temp = FIRST(i.getNowID(), bnfs);
            if ((temp.find(-3)==temp.end())) {
                b = false; // 找到第一个不含有空的First(V)
            } else {
                temp.erase(-3);
            }
            firstset.insert(temp.begin(),temp.end());
            ++i;
            nowid = i.getNowID();
        }
        if (b) firstset.insert(-3); // 如果最后都没找到,则认为可空
    }
    return firstset;
}

set<int> ItemCollection::FIRST(vector<int>& Vlist,const set<int> lookahead, const vector<BNF*>& bnfs) {
    set<int> firstset;
    for (int i = 0; i< Vlist.size(); ++i) {
        int id = Vlist[i];
        int index = vmap->VnIDtoIndex(id);
        if (index == -1) {
            firstset.insert(id);
            return firstset;
        }
        set<int> tempset = FIRST(id,bnfs);

        if ((!NULLABLE[index]) && (tempset.find(-3)==tempset.end())) {
            tempset.erase(-3);
            firstset.insert(tempset.begin(), tempset.end());
            return firstset;
        }
        tempset.erase(-3);
        firstset.insert(tempset.begin(), tempset.end());
    }
    firstset.insert(lookahead.begin(),lookahead.end());\
    auto p = firstset.find(-3);
    if (p!=firstset.end())
        firstset.erase(p);
    return firstset;
}

void ItemCollection::MakeNULLABLE(vector<bool>& NULLABLE,const vector<BNF*>& bnfs) {
    for (auto p = bnfs.begin(); p != bnfs.end(); ++p) {
        BNF* bnf = *p;
        int i = bnf->getRoot()->id;
        if (bnf->getBNFdata().size() == 0){
            NULLABLE[vmap->VnIDtoIndex(i)] = true;
        }
    }
}


void ItemCollection::MakeNULLANDFRIST(const vector<BNF*>& bnfs) {
    NULLABLE.resize(vmap->constSize-vmap->constMax,false);
    FirstMap.resize(vmap->constSize-vmap->constMax);
    ifFirstFinded.resize(vmap->constSize-vmap->constMax,false);
    MakeNULLABLE(NULLABLE,bnfs);


    // ==== for debug ====
    /*
    for (int i = vmap->constMax+1; i < vmap->constSize; ++i) {
        printf("------------------------\n");
        auto itemset = findItems(i,bnfs);
        for (auto p = itemset.begin(); p != itemset.end(); ++p) {
            const Item& i = *p;
            i.getBNF()->print_bnf();
        }
        if (NULLABLE[vmap->VnIDtoIndex(i)]) printf("null(%d)=true\n",i); else printf("null(%d)=false\n",i);
        printf("first(%d)={",i);
        for (auto p : FIRST(i,bnfs)) {
            printf(" %d",p);
        }
        printf("}\n");
    }
    */
}



void ItemCollection::CLOSURE1(const vector<BNF*>& bnfs){
    vector<Item> itemlist(CoreItems.begin(),CoreItems.end());
    for (auto p : Items) itemlist.push_back(p);
    bool b = true;
    while (b) { // 由于向前看运算符的确定和闭包的遍历顺序不同，必须遍历多遍才能找全
        int i = 0;
        b = false;
        while (i < itemlist.size()) {
            Item item = itemlist[i];
            int id = item.getNowID();
            auto itemset = findItems(id,bnfs);
            for (Item& newitem : itemset) {
                Item temp(item); ++temp;
                vector<int> Vlist;
                for (int i = temp.getItempoint(); i < temp.getSize(); ++i) {
                    Vlist.push_back(temp.getNowID());
                    ++temp;
                }
                set<int> FirstSet = FIRST(Vlist,item.getLookahead(),bnfs);
                for (auto q : FirstSet) {
                    newitem.addLookahead(q);
                }
                auto q = find(itemlist.begin(),itemlist.end(),newitem);
                if (q==itemlist.end()) {
                    itemlist.push_back(newitem);
                    Items.insert(newitem);
                    b = true;
                } else {
                    // 如果有尚未找到的向前看操作符，更新队列中的及Items表中的
                    Item& olditem = *q;
                    for (auto j : newitem.getLookahead()) {
                        if (olditem.getLookahead().find(j)==olditem.getLookahead().end()) {
                            olditem.addLookahead(j);
                            Items.erase(olditem);
                            Items.insert(olditem);
                            b = true;
                        }
                    }
                }
            }
            ++i;
        }
    }
}

void printSetFrom(set<Item>& items) {
    for (auto p = items.begin(); p != items.end(); ++p) {
        const Item& item = *p;
        printf("\t");
        item.getBNF()->print_bnf(item.getItempoint());
        printf("\t");
        for (auto q = item.getLookahead().begin(); q != item.getLookahead().end(); ++q) {
            int ahead = *q;
            printf("/%d",ahead);
        }
        printf("\n");
    }
}

void ItemCollection::printSet() {
    printSetFrom(CoreItems);
    printSetFrom(Items);
}

void ItemCollection::printSpread() {
    for (auto q = getCoreItems().begin(); q != getCoreItems().end(); ++q) {
        const Item& item = *q;
        printf("From: I%d:\t",getID());
        item.getBNF()->print_bnf(item.getItempoint());
        if (SpreadMap.find(item) == SpreadMap.end()) continue;
        const vector<pair<ItemCollection*,Item>>& smap = SpreadMap.at(item);
        printf("To:");
        for (auto r = smap.begin(); r != smap.end(); ++r) {
            ItemCollection* pItems = r->first;
            const Item& toitem =  r->second;
            printf("\tI%d\t",pItems->getID());
            toitem.getBNF()->print_bnf(toitem.getItempoint());
        }
    }
}
