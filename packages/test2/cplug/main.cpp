/* 
* @Author: sxf
* @Date:   2015-12-26 09:53:58
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 10:55:25
*/

#include <iostream>
#include "CodeGenContext.h"
#include "Model/nodes.h"

using namespace std;

static LValue hello_macro(CodeGenContext* context, Node* node) {
	printf("Hello World!\n");
	return NULL;
}

static const FuncReg macro_funcs[] = {
	{"hello", hello_macro},
	{NULL, NULL}
};

extern "C" {
	extern void HelloWorld();
	extern void test2_elite_plugin_init(CodeGenContext* context) {
		HelloWorld();
		printf("test2_elite_plugin_init\n");
		if (context == NULL) printf("Error for context\n");
		else context->AddOrReplaceMacros(macro_funcs);
	}
}