#include "LR_parser.h"
#include "BNFParser.h"
#include "LALRTable.h"
#include "ScriptRunner.h"
#include "Grammer_Node.h"


LR_parser::LR_parser()
{
	
}

LR_parser::~LR_parser()
{

}


void LR_parser::ExtendBNF()
{
    mainbnf = new BNF();
    State* s = new State();
    s->state_class = "<Main>";
    s->state_type = statement;
    s->id = vmap.InsertVn("<Main>");
    mainbnf->setRoot(s);
    mainbnf->setID(-1);
    mainbnf->addBNFdata(bnflist[0]->getRoot());
}

void LR_parser::MakeID()
{
    // print debug message
    printf("========= print V* =========\n");
    vmap.printAll();
    printf("============================\n");
    for (auto p = bnflist.begin(); p != bnflist.end(); ++p) {
        BNF* bnf = *p;
        State* s = bnf->getRoot();
        s->id = vmap.getVn(s->state_class);
        const vector<State*>& vec = bnf->getBNFdata();
        for (auto q = vec.begin(); q != vec.end(); ++q) {
            s = *q;
            if (s->state_type == constant)
            s->id = vmap.getConst(s->state_const);
            else if (s->state_type == temporality || s->state_type == statement )
            s->id = vmap.getVn(s->state_class);
            else if (s->state_type == epsilon )
            s->id = 0;
            else if (s->state_type == terminal )
            s->id = vmap.getVt(s->state_class);
        }
    }
}

void print_ItemCollection(vector<ItemCollection*> vec) {
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        printf("I%d:",items->getID());
        items->printSet();
    }
}

void LR_parser::print_GOTO(vector<ItemCollection*> vec) {
    printf("======= GOTO =======\n");
    for (int i = 0; i< vmap.constSize; ++i) {
        printf("\t%d",i);
    }
    printf("\n");
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        printf("I%d:",items->getID());
        for (int i = 0; i< vmap.constSize; ++i) {
            ItemCollection* gotoitems = items->GOTO(i);
            int gotoid = -1;
            if (gotoitems != NULL) {
                gotoid = gotoitems->getID();
            }
            printf("\t%d",gotoid);
        }
        printf("\n");
    }


    printf("======= Spread =======\n");
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;

        items->printSpread();
        printf("\n");
    }

}

void LR_parser::BuildParser()
{
    ExtendBNF();
    MakeID(); // for each state, make a ID for it
    printf("Create LR0\n");
    // 创建LR0项集族
    vector<ItemCollection*> vec = ItemCollection::MakeLR0Items(&vmap, mainbnf, bnflist);
//    printf("======== print LR0 Collection ========\n");
//    print_ItemCollection(vec);
    // 构建LALR项集族
    printf("MakeLALRItems\n");
    ItemCollection::MakeLALRItems(vec,bnflist);
    printf("======== print LR1 Collection ========\n");
    print_ItemCollection(vec);
    print_GOTO(vec);
//    printf("test: \t %d %d %d\n",vmap.constMax+1,vec.size(),vmap.constSize);
    table = (LRTable*)new LALRTable(vmap.constMax+1,vec.size(),vmap.constSize);
    table->BuildTable(vec);
//    table->printTable();
}

void LR_parser::BuildParser(const char* filename) {
    printf("add bnf\n");
    AddBNF(filename);
    printf("build parser\n");
    BuildParser();
}

extern char* WCharToChar(const wchar_t* data,int& size);

void LR_parser::AddBNF(const char* filename) {
    // ask the ID name from the lex
    int size = lex->getRuleSize();
    vmap.constSize = size-1;
    printf("Size: %d\n", size);

    int tt;
    for (int i = 1; i< size; ++i) {
        printf("VMap: %S %d\n",lex->getRule(i), i);
        vmap.InsertVt(WCharToChar(lex->getRule(i), tt), i);
    }
    BNFParser* bnfparser = new BNFParser();
    State* root = bnfparser->Analysis(filename);
    if (root == NULL) {
        printf("Error State\n");
        delete bnfparser;
        return;
    }
    bnfparser->printTree();
    bnflist = BNF::BuildAllBNF(root,vmap);
    printf("BuildAllBNF");
    delete bnfparser;
}

int LR_parser::Parse(Grammer_Node* root)
{
    core.setLex(lex);
    core.setBnflist(&bnflist);
    core.setTable(table);
    core.setVMap(&vmap);
    core.setAst(root);
    core.Run();
    return 0;
}

void LR_parser::setLex(LexInterface* _lex)
{
    lex = _lex;
}
