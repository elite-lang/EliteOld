/* 
* @Author: sxf
* @Date:   2015-12-24 17:12:55
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 17:14:47
*/

#include "LuaGenFunction.h"

LuaGenFunction::LuaGenFunction() {
}

LuaGenFunction::LuaGenFunction(int lua_code) {
	this->lua_code = lua_code;
}

LuaGenFunction::~LuaGenFunction() {
}

LValue LuaGenFunction::call(CodeGenContext*, Node*) {
	return nullptr;
}

