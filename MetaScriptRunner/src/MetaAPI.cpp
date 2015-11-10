/* 
* @Author: sxf
* @Date:   2015-11-07 15:46:24
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-07 15:56:05
*/

#include "oolua/oolua.h"

int include_meta_api(const char* filename) {

}

// 这个接口最好做成可变参数的，而不是现在这种
int add_bnf_meta_api(const char* bnf) {

}

int add_bnf_file_meta_api(const char* filename) {

}

int load_default_bnf() {

}

int load_empty_bnf() {

}

int parse_file(const char* filename) {

}

int print_bnf() {

}


OOLUA_CFUNC(include_meta_api, l_include_meta_api)

extern void InitMetaAPI(lua_State* L) {
	set_global(L, "include", l_include_meta_api);
}