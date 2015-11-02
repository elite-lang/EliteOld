/* 
* @Author: sxf
* @Date:   2015-01-03 13:21:45
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 13:28:44
*/

#include "LALRTable.h"

LALRTable::LALRTable(){

    
}

LALRTable::LALRTable(const LALRTable& other){

}

LALRTable::~LALRTable(){

}

LALRTable& LALRTable::operator=(const LALRTable& other){
	return *this;
}

bool LALRTable::operator==(const LALRTable& other){
	return true;
}

void LALRTable::BuildReduce(int id,const set<Item>& itemset) {
    for (const Item& q : itemset) {
        if (q.getNowID() == -1)
            for (int la : q.getLookahead()) {
                int bnfid = q.getBNF()->getID();
                if (la == 0 && bnfid == -1)
                    Action[id][la] = 'a';
                else {
                    Action[id][la] = 'r';
                }
                Goto[id][la] = bnfid;
            }
    }
}

void LALRTable::BuildTable(vector<ItemCollection*> LALRItems){
    for (auto pItems : LALRItems) {
        int id = pItems->getID();
        for (int i = 0; i < VSum; ++i) {
            ItemCollection* objItems = pItems->GOTO(i);
            int obj = -1;
            if (objItems != NULL) obj = objItems->getID();
            Goto[id][i] = obj;
            if (obj != -1 && i < constSum)
                Action[id][i] = 's';
        }
        BuildReduce(id,pItems->getCoreItems());
        BuildReduce(id,pItems->getItems());
    }
}

char LALRTable::ACTION(int state, int id){
    if (state < 0 || state >= stateSum) return 0;
    if (id < 0 || id >= constSum) return 0;
    return Action[state][id];
}

int LALRTable::GOTO(int state, int id){
    if (state < 0 || state >= stateSum) return 0;
    if (id < 0 || id >= VSum) return 0;
    return Goto[state][id];
}

void LALRTable::printTable() {
    printf("=========== LALR TABLE ==========\n");
    for (int s = 0; s < VSum; ++s) {
        printf("\t%d",s);
    }
    printf("\n");
    for (int s = 0; s < stateSum; ++s) {
        printf("I%d:",s);
        for (int i = 0; i < VSum; ++i) {
            printf("\t");
            if (ACTION(s,i)=='a') { printf("acc"); continue;  }
            if (ACTION(s,i))
                printf("%c",ACTION(s,i));
            printf("%d",GOTO(s,i));
        }
        printf("\n");
    }
}
