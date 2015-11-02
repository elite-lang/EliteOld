/* 
* @Author: sxf
* @Date:   2015-01-03 18:42:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 18:43:08
*/

#ifndef LR_CORE_H
#define LR_CORE_H

#include "LexInterface.h"
#include "Grammer_Node.h"
#include "ScriptRunner.h"
#include "LRTable.h"
#include <stack>
using namespace std;

class LRCore 
{
public:
    LRCore() { script_runner = new ScriptRunner(); }
    ~LRCore() { delete script_runner; }
    Grammer_Node* Run();
    
    //======= setter and getter =========
    
    void setLex(LexInterface* _l) { lex = _l; }
    LexInterface* getLex() { return lex; } 
    
    void setTable(LRTable* _t) { table = _t; }
    LRTable* getTable() { return table; }
    
    void setVMap(VMap* _v) { vmap = _v; }
    void setBnflist(vector<BNF*>* _bnfs) { bnflist = _bnfs; }
    void setAst(Grammer_Node* _ast) { ast = _ast; }
    void setScriptRunner(ScriptRunner* _s) { script_runner = _s; }
private:
    
    void Shift(int,Token* t); // 移入
    void Shift(int,Grammer_Node*); // 移入,处理节点用

    // 三个参数分别是，要规约的语法项id，规约时的父节点
    int Reduce(int,Grammer_Node*&); // 规约

    // Token过滤器，能够检测词法中的内容
    // 如果发现有和语法中定义的const，内容相同的Token
    // 会将该返回的id改写为const的id
    Token* TokenFliter(Token*);

    Grammer_Node* ast;
    // 分析栈
    deque<int> LRStack;
    // 节点栈
    stack<Grammer_Node*> NodeStack;
    // 词法分析程序
    LexInterface* lex;
    // BNF列表
    vector<BNF*>* bnflist;
    // 语法符号对照表
    VMap* vmap;
    // LR分析表
    LRTable* table;
    // 脚本执行器
    ScriptRunner* script_runner;
};

#endif // LR_CORE_H
