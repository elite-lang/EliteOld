/* 
* @Author: sxf
* @Date:   2015-12-24 17:00:30
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 17:05:22
*/


#ifndef LUA_GEN_FUNCTION_H
#define LUA_GEN_FUNCTION_H

class LuaGenFunction : public ICodeGenFunction
{
public:
	LuaGenFunction();
	~LuaGenFunction();
	
	virtual LValue call(CodeGenContext*, Node*);
private:
	
};



#endif // LUA_GEN_FUNCTION_H
