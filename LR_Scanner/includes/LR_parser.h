/* 
* @Author: sxf
* @Date:   2015-01-01 19:40:28
* @Last Modified by:   sxf
* @Last Modified time: 2015-04-20 09:52:59
*/

#ifndef LR_PARSER_H
#define LR_PARSER_H

#include "afx.h"
#include "Parser.h"
#include "BNF.h"
#include "LRTable.h"
#include "LRCore.h"
#include <vector>
#include <map>
#include "VMap.h"
using namespace std;

class LR_parser : public Parser
{
public:
  // constructors
    LR_parser();
    ~LR_parser();
  
    // 构建解析器
    virtual void BuildParser();
    
    // 先AddBNF，再构建解析器
    virtual void BuildParser(const char*);

    // 将EBNF的描述文件传入，用来构建LR语法解析器
    virtual void AddBNF(const char*);  

    // 解析文本
    virtual int Parse(Grammer_Node* root);

    // 设置词法分析器
    virtual void setLex(LexInterface*);

    virtual void setBaseVtSize(int size) {
        vmap.constSize = size;
    }

private:
    LexInterface* lex;
    vector<BNF*> bnflist;
    
    BNF* mainbnf; // 增广文法中的根元素
    
    VMap vmap;
    
    // 分析器内核
    LRCore core;
    // LR分析表
    LRTable* table;
    
    // 扩展 BNF，增加根元素
    void ExtendBNF();
    // 给每一个state加上id
    void MakeID();

    void print_GOTO(vector<ItemCollection*> vec);
};

#endif // LR_PARSER_H
