/* 
* @Author: sxf
* @Date:   2015-11-11 16:00:38
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-11 16:47:32
*/


#include "Worker.h"
#include "Lex.h"
#include "Parser.h"

void Worker::Init(LexInterface* l, Parser* p, ScriptRunner s, CodeGen* c) {
    p->setLex(l);
    p->setScriptRunner(s);
    lex = l; parser = p; script_runner = s; codegen = c;
    l->Init();
    p->BuildParser();
}

void Worker::Run(const char* input, const char* output) {
	lex->setData(input);
	Grammer_Node* root = Grammer_Node::NewNode();
	parser->Parse(root);
	c->Make(output);
}

static Worker* Worker::CreateDefault(const char* lex_cfg, const char* parser_cfg) {
	Lex* l = new Lex();
	l->ReadConfig(lex_cfg);
	Parser* p = Parser::NewLRParser();
	p->AddBNF(parser_cfg);
	ScriptRunner* s = MetaScriptRunner::Create();
	CodeGen* c = RedCodeGen::Create();
	return Create(l, p, s, c);
}

static Worker* Worker::Create(LexInterface* l, Parser* p, ScriptRunner s, CodeGen* c) {
	Worker* k = new Worker();
	k->Init(l, p, s, c);
	return k;
}

Worker::Worker() {

}

Worker::~Worker() {

}
