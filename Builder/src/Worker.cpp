/*
* @Author: sxf
* @Date:   2015-11-11 16:00:38
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 15:36:14
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

}

void Worker::Run(const char* input, const char* output) {
	Node* node = MakeAST(input);
	codegen->PreScan(node);
	codegen->Make(node, output, "Main");
}

Node* Worker::MakeAST(const char* input) {
	lex->setData(input);
	Grammer_Node* root = Grammer_Node::NewNode();
	int err = parser->Parse(root);
    if (err) exit(1);
	Node* node = script_runner->getRoot();
	if (node == NULL) {
		printf("分析器异常，返回为NULL\n");
		exit(1);
	}
	node->print(0);
    return node;
}

void Worker::MetaGen(const char* output) {
	codegen->MakeMeta(output, "Meta");
}


Worker* Worker::CreateDefault(const char* lex_cfg,
	const char* parser_cfg, const char* package_path, Builder* b) {
	Lex* l = new Lex();
	Parser* p = Parser::NewLRParser();
	MetaScriptRunner* s = MetaScriptRunner::Create();
	RedCodeGen* c = RedCodeGen::Create();

	// 配置联系
    p->setLex(l);
    p->setScriptRunner(s);

	// 向脚本引擎中注入更多接口
	c->Init();
	s->setCodeGenContext(c->getContext());

    // 向脚本引擎中注入各对象
	s->setLex(l);
	s->setParser(p);
	s->setBuilder(b);

	// 配置外置插件
	s->setUpLoader(package_path);

    // 配置词法分析器和语法分析器
	l->ReadConfig(lex_cfg);
	p->AddBNF(parser_cfg);

    printf("Create Default\n");

	return Create(l, p, s, c, b);
}

Worker* Worker::Create(LexInterface* l, Parser* p, ScriptRunner* s, CodeGen* c, Builder* b) {
	Worker* k = new Worker();
    k->builder = b;
	k->Init(l, p, s, c);
	return k;
}

Worker::Worker() {

}

Worker::~Worker() {

}
