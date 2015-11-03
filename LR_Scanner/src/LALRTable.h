/* 
* @Author: 笑凡
* @Date:   2014-12-31 09:31:22
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 13:25:22
*/

#ifndef LALR_TABLE_H
#define LALR_TABLE_H

#include "LRTable.h"

class LALRTable : public LRTable
{

public:
    LALRTable();
    LALRTable(const LALRTable& other);
    ~LALRTable();
    LALRTable& operator=(const LALRTable& other);
    bool operator==(const LALRTable& other);
    LALRTable(int _constSum,int _stateSum,int _VSum) {
        constSum = _constSum; stateSum = _stateSum; VSum = _VSum;
        Goto.resize(stateSum);
        Action.resize(stateSum);
        for(auto& p:Goto) p.resize(VSum,0);
        for(auto& p:Action) p.resize(constSum,0);
    }

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

    void BuildReduce(int id,const set<Item>& itemset);
};


#endif // LALR_TABLE_H
