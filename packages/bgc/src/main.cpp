/* 
* @Author: sxf
* @Date:   2015-12-26 09:53:58
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 17:03:08
*/

#include <iostream>
#include "CodeGenContext.h"
#include "Model/nodes.h"

using namespace std;

static LValue new_macro(CodeGenContext* context, Node* node) {
	printf("Happy New Year!\n");
	TypeNode* tn = (TypeNode*) node;
	LValue t = context->FindSrcType(tn->getTypeName());

	// 第二个参数，构造函数表
	node = node->getNext();

	// 第三个参数，维度信息
	vector<LValue> args;
	node = node->getNext();
	if (node != NULL)
		for (Node* p = node->getChild(); p != NULL; p = p->getNext()) {
			args.push_back(p->codeGen(context));
		}
	if (args.size() == 0) {
		return context->getLLCG()->New(t,args);
	} else {
		return context->getLLCG()->NewArray(t, args);
	}
	return NULL;
}

static const FuncReg macro_funcs[] = {
	{"new", new_macro},
	{NULL, NULL}
};

extern "C" {
	extern void bgc_elite_plugin_init(CodeGenContext* context) {
		if (context == NULL) printf("Error for context\n");
		else context->AddOrReplaceMacros(macro_funcs);
	}
}