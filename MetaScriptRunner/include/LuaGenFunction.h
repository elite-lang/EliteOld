/* 
* @Author: sxf
* @Date:   2015-12-24 17:00:30
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 17:14:29
*/


#ifndef LUA_GEN_FUNCTION_H
#define LUA_GEN_FUNCTION_H

#include "ICodeGenFunction.h"

/**
 * @brief 这个类是Lua的回调函数实现
 */
class LuaGenFunction : public ICodeGenFunction
{
public:
	LuaGenFunction();
	LuaGenFunction(int lua_code);
	~LuaGenFunction();
	
	virtual LValue call(CodeGenContext*, Node*);
private:
	int lua_code;
};



#endif // LUA_GEN_FUNCTION_H
