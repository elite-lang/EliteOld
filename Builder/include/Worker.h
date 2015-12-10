/* 
* @Author: sxf
* @Date:   2015-11-11 13:52:11
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-07 10:27:04
*/
#ifndef WORKER_H
#define WORKER_H

class LexInterface;
class Parser;
class ScriptRunner;
class CodeGen;

class Worker
{
public:
	void Init(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c);
	void Run(const char* input, const char* output);

	static Worker* CreateDefault(const char* lex_cfg, const char* parser_cfg);
	static Worker* Create(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c);

	LexInterface* getLex() { return lex; }
	Parser* getParser() { return parser; }
	ScriptRunner* getScriptRunner() { return script_runner; }
	CodeGen* getCodegen() { return codegen; }
	
	Worker();
	~Worker();
protected:
	LexInterface* lex;
	Parser* parser;
	ScriptRunner* script_runner;
	CodeGen* codegen;
};



#endif // WORKER_H
