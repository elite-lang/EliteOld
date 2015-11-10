/* 
* @Author: sxf
* @Date:   2015-01-02 16:29:28
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 10:31:27
*/

#ifndef PARSER_H
#define PARSER_H

class Grammer_Node;
class ScriptRunner;
class LexInterface;

class Parser {
public:
    // 构建解析器
    virtual void BuildParser() = 0;

    // 先AddBNF，再构建解析器
    virtual void BuildParser(const char*) = 0;

    // 将EBNF的描述文件传入，用来构建LR语法解析器
    virtual void AddBNF(const char*) = 0;

    // 解析文本
    virtual int Parse(Grammer_Node* root) = 0;

    // 设置词法分析器
    virtual void setLex(LexInterface*) = 0;

    // set the Base Vt size of Lex
    virtual void setBaseVtSize(int size) = 0;

    // 设置脚本解析器
    virtual void setScriptRunner(ScriptRunner* sr) = 0;

    // 构建LR解析器对象
    static Parser* NewLRParser();
};

#endif // PARSER_H
