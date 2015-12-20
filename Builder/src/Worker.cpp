/* 
* @Author: sxf
* @Date:   2015-11-11 16:00:38
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-20 21:47:28
*/


#include "Worker.h"
#include "Lex.h"
#include "Parser.h"
#include "RedCodeGen.h"
#include "MetaScriptRunner.h"
#include "Grammer_Node.h"
#include <cstring>


void Worker::Init(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c) {
    lex = l; parser = p; script_runner = s; codegen = c;

	// 初始化词法分析器与语法分析器
	l->Init(NULL);
    p->BuildParser();
    c->Init();
}

void Worker::Run(const char* input, const char* output) {
	lex->setData(input);
	Grammer_Node* root = Grammer_Node::NewNode();
	parser->Parse(root);
	Node* node = script_runner->getRoot();
	if (node == NULL) {
		printf("分析器异常，返回为NULL\n");
		exit(1);
	}
	node->print(0);
	codegen->PreScan(node);
	codegen->Make(node, output, "Main");
}

void Worker::MetaGen(const char* output) {
	codegen->MakeMeta(output, "Meta");
}


Worker* Worker::CreateDefault(const char* lex_cfg, const char* parser_cfg) {
	Lex* l = new Lex();
	Parser* p = Parser::NewLRParser();
	ScriptRunner* s = MetaScriptRunner::Create();
	CodeGen* c = RedCodeGen::Create();
	
	// 配置联系
    p->setLex(l);
    p->setScriptRunner(s);

    // 配置词法分析器和语法分析器
	l->ReadConfig(lex_cfg);
	p->AddBNF(parser_cfg);

	return Create(l, p, s, c);
}

Worker* Worker::Create(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c) {
	Worker* k = new Worker();
	k->Init(l, p, s, c);
	return k;
}

Worker::Worker() {

}

Worker::~Worker() {

}
