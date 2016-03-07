/*
* @Author: sxf
* @Date:   2015-11-11 13:52:11
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 15:35:30
*/
#ifndef WORKER_H
#define WORKER_H

class LexInterface;
class Parser;
class ScriptRunner;
class CodeGen;
class Builder;
class Node;
/**
 * @brief 工作流类, 是词法分析器, 语法分析器, 元脚本解析器, 后端代码生成器整合后的工作流
 */
class Worker
{
public:
	void Init(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c);
	void Run(const char* input, const char* output);
	void MetaGen(const char* output);
	Node* MakeAST(const char* input);

	static Worker* CreateDefault(const char* lex_cfg, const char* parser_cfg, const char* package_path, Builder* b);
	static Worker* Create(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c, Builder* b);

	LexInterface* getLex() { return lex; }
	Parser* getParser() { return parser; }
	ScriptRunner* getScriptRunner() { return script_runner; }
	CodeGen* getCodegen() { return codegen; }
	Builder* getBuilder() { return builder; }

	Worker();
	~Worker();
protected:
	LexInterface* lex;
	Parser* parser;
	ScriptRunner* script_runner;
	CodeGen* codegen;
	Builder* builder;
};



#endif // WORKER_H
