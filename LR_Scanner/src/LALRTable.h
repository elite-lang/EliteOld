/* 
* @Author: 笑凡
* @Date:   2014-12-31 09:31:22
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-28 13:30:05
*/

#ifndef LALR_TABLE_H
#define LALR_TABLE_H

#include "LRTable.h"
#include "BNFParser.h"

class LALRTable : public LRTable
{

public:
    LALRTable(int _constSum, int _stateSum, int _VSum, BNFParser* bnfparser);
    LALRTable(const LALRTable& other);
    ~LALRTable();
    LALRTable& operator=(const LALRTable& other);
    bool operator==(const LALRTable& other);

    virtual void BuildTable(vector<ItemCollection*>);
    virtual char ACTION(int, int);
    virtual int GOTO(int, int);
    virtual void printTable();
private:
    // 经过调整的总数，包含结束符0
    int constSum; // Vt的总数
    int stateSum; // 状态的总数
    int VSum;     // V的总数

    vector < vector <int> > Goto;
    vector < vector <char> > Action;

    BNFParser* bnfparser;
    bool PdPriority(int id, int c, const Item& item);
    void BuildReduce(int id,const set<Item>& itemset);
};


#endif // LALR_TABLE_H
