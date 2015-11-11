/* 
* @Author: sxf
* @Date:   2015-11-07 15:46:24
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-11 19:54:12
*/

#include "oolua/oolua.h"
#include "Model/nodes.h"

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
	node_root = (Node*)p;
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

static int l_make_pair_meta_api(lua_State* L) {

	return 1;
}
	

static int l_setroot_meta_api(lua_State* vm) {
	OOLUA_C_FUNCTION(void, setroot_meta_api, light_p< Node* >)
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
/*	OOLUA::set_global(L, "makePair", l_make_pair_meta_api);
	OOLUA::set_global(L, "newNode", l_newnode_meta_api);
	OOLUA::set_global(L, "getList", l_getlist_meta_api);
	OOLUA::set_global(L, "newParent", l_newparent_meta_api); */
}