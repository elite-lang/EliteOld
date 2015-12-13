/* 
* @Author: sxf
* @Date:   2015-11-07 15:46:24
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-13 11:24:49
*/

#include "oolua/oolua.h"
#include "Model/nodes.h"
#include "assert.h"

using namespace OOLUA;

static int include_meta_api(const char* filename) {

}

// 这个接口最好做成可变参数的，而不是现在这种
static int add_bnf_meta_api(const char* bnf) {

}

static int add_bnf_file_meta_api(const char* filename) {

}

static int load_default_bnf() {

}

static int load_empty_bnf() {

}

static int parse_file(const char* filename) {

}

static int print_bnf() {

}

Node* node_root;

static void setroot_meta_api(Node* p) {
	node_root = p;
}

static Node* newnode_meta_api() {
	return Node::Create();
}

static Node* newparent_meta_api(Node* n) {
	return Node::Create(n);
}

static Node* getlist_meta_api(Node* n) {
	return Node::getList(n);
}


static Node* new_stringnode_meta_api(const char* str) {
	return StringNode::Create(str);
}

static Node* new_idnode_meta_api(const char* str) {
	return IDNode::Create(str);
}


static Node* new_intnode_meta_api(const char* str) {
	return IntNode::Create(str);
}

static Node* new_floatnode_meta_api(const char* str) {
	return FloatNode::Create(str);
}

static Node* new_typenode_meta_api(const char* str, bool is_const, bool is_source) {
	return TypeNode::Create(str, is_const, is_source);
}


static void add_brother_meta_api(Node* node1, Node* node2) {
	node1->addBrother(node2);
}

static void add_children_meta_api(Node* node1, Node* node2) {
	node1->addChildren(node2);
}

static void adddimension_meta_api(Node* node) {
	if (node->isTypeNode()) {
		TypeNode* n = (TypeNode*) node;
		n->addDimension();
	}
}

static int l_make_list_meta_api(lua_State* L) {
	int argc = lua_gettop(L);  
	Node** plist = new Node* [argc];
	for (int i = 1 ; i <= argc ; ++i ) {  
		Node* node = (Node*)lua_touserdata(L, -i);
		plist[argc-i] = node;
	}
	lua_pop(L, argc);
	Node* ans = Node::makeList(argc, plist);
	assert(ans != NULL);
	delete[] plist;
	lua_pushlightuserdata(L, ans);
	return 1;
}


static int l_setroot_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(void, setroot_meta_api, light_p< Node* >)
}

static int l_newnode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, newnode_meta_api)
}

static int l_newparent_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, newparent_meta_api, light_p< Node* >)
}

static int l_getlist_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, getlist_meta_api, light_p< Node* >)
}

static int l_new_stringnode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, new_stringnode_meta_api, const char*)
}

static int l_new_idnode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, new_idnode_meta_api, const char*)
}

static int l_new_intnode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, new_intnode_meta_api, const char*)
}

static int l_new_floatnode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, new_floatnode_meta_api, const char*)
}

static int l_addbrother_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(void, add_brother_meta_api, light_p< Node* >, light_p< Node* >)
}

static int l_addchildren_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(void, add_children_meta_api, light_p< Node* >, light_p< Node* >)
}

static int l_new_typenode_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(light_return< Node* >, new_typenode_meta_api, const char*, bool, bool)
}

static int l_adddimension_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(void, adddimension_meta_api, light_p< Node* >)
}

OOLUA_CFUNC(include_meta_api, l_include_meta_api)
/*
OOLUA_CFUNC(setroot_meta_api, l_setroot_meta_api)
OOLUA_CFUNC(newnode_meta_api, l_newnode_meta_api)
OOLUA_CFUNC(getlist_meta_api, l_getlist_meta_api)
OOLUA_CFUNC(newparent_meta_api, l_newparent_meta_api)
*/

extern void InitMetaAPI(lua_State* L) {
	OOLUA::set_global(L, "include", l_include_meta_api);
	OOLUA::set_global(L, "setRoot", l_setroot_meta_api);
	OOLUA::set_global(L, "makeList", l_make_list_meta_api);
	OOLUA::set_global(L, "newNode", l_newnode_meta_api);
	OOLUA::set_global(L, "newParent", l_newparent_meta_api);
	OOLUA::set_global(L, "newStringNode", l_new_stringnode_meta_api);
	OOLUA::set_global(L, "newIDNode", l_new_idnode_meta_api);
	OOLUA::set_global(L, "newIntNode", l_new_intnode_meta_api);
	OOLUA::set_global(L, "newFloatNode", l_new_floatnode_meta_api);
	OOLUA::set_global(L, "newTypeNode", l_new_typenode_meta_api);
	OOLUA::set_global(L, "getList", l_getlist_meta_api);
	OOLUA::set_global(L, "addBrother", l_addbrother_meta_api); 
	OOLUA::set_global(L, "addChildren", l_addchildren_meta_api);  
	OOLUA::set_global(L, "addDimension", l_adddimension_meta_api);
}