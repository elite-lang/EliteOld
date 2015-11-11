/* 
* @Author: sxf
* @Date:   2015-11-02 18:58:29
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-10 20:16:27
*/

#include "PCodeScriptRunner.h"
#include "Grammer_Node.h"
#include "lua.hpp"

static ScriptRunner* runner;
static int cachecode;
static IDTable* idtable;
static CodeGenerator* generator;

PCodeScriptRunner::PCodeScriptRunner() {
	id_table = new IDTable();
    idtable = this->id_table;
    code_generator = new CodeGenerator();
    generator = this->code_generator;
}

PCodeScriptRunner::~PCodeScriptRunner() {
	delete id_table;
    delete code_generator;
}

void PCodeScriptRunner::Finished() {
    printf("finished!\n");
	code_generator->WriteFile("test.pco");
}

// lua 输入参数：符号x 返回 lua表t 包含t.kind t.type t.level t.address
static int find_id(lua_State * L) {
    const char* str = lua_tostring(L,-1);
    const id* pid = idtable->find(str);
    printf("find %s\n",str);
    if (pid == 0) {
        lua_pushnil(L);
        return 1;
    }
    // 构造一张lua表将符号表的项目返回回去
    lua_newtable(L);
    lua_pushinteger(L,pid->kind);
    lua_setfield(L,-2,"kind");
    lua_pushinteger(L,pid->type);
    lua_setfield(L,-2,"type");
    lua_pushinteger(L,pid->level);
    lua_setfield(L,-2,"level");
    lua_pushinteger(L,pid->address);
    lua_setfield(L,-2,"address");
    return 1;
}

// lua 输入参数：符号x kind type address 返回bool 是否保存成功
static int save_id(lua_State * L) {
    int kind,type,address;
    const char* str = lua_tostring(L,-4);
    kind = lua_tointeger(L,-3);
    type = lua_tointeger(L,-2);
    address = lua_tointeger(L,-1);
    lua_pop(L,4);
    const id* pid = idtable->find(str);
    if (pid != NULL && pid->level == idtable->getLevel()) {
        lua_pushboolean(L, 0); return 1; // 判断是同级要存入相同符号，要报符号表异常
    }

    id* newid = new id();
    newid->level = idtable->getLevel();
    newid->kind = kind;
    newid->type = type;
    newid->address = address;
    idtable->insert(str,newid);
    printf("save: %s\n",str);
    lua_pushboolean(L, 1); return 1;
}

// lua 输入参数：指令p 参数a 返回bool 是否生成成功
static int make_code(lua_State * L) {
    int p,l,a;
    if (lua_gettop(L)<=1) {
        p = lua_tointeger(L,-1); lua_pop(L,1);
        l = -1; a = -1;
    }
    else if (lua_gettop(L)<=2) {
        a = lua_tointeger(L,-1); lua_pop(L,1);
        p = lua_tointeger(L,-1); lua_pop(L,1);
        l = -1;
    } else {
        a = lua_tointeger(L,-1); lua_pop(L,1);
        l = lua_tointeger(L,-1); lua_pop(L,1);
        p = lua_tointeger(L,-1); lua_pop(L,1);
    }
    if (l != -1) {
        if (l == 0) // 表示寻找的是全局变量
            l = -1; // VM中用-1表示是一个全局变量
        else
            l = idtable->getLevel() - l;
        generator->Write(p,l,a);
    } else {
        if (a == -1) {
            generator->Write(p);
        } else {
            generator->Write(p,a);
        }
    }
    lua_pushboolean(L, 1); return 1;
}


static int write_code(lua_State * L) {
    int p, a;
    a = lua_tointeger(L,-1); lua_pop(L,1);
    p = lua_tointeger(L,-1); lua_pop(L,1);
    generator->WritePointer(p,a);
    return 0;
}


static int now_pointer(lua_State * L) {
    lua_pushinteger(L, generator->getPointer()); return 1;
}


static int push_stack(lua_State * L) {
    printf("stack push!\n");
    idtable->push();
    return 0;
}

static int pop_stack(lua_State * L) {
    printf("stack pop!\n");
    idtable->pop();
    return 0;
}

static int exitfunc(lua_State * L) {
    // TODO: 这里需要加入一个打断方法,使得语法分析器能够被异常打断
    return 0;
}

void PCodeScriptRunner::Init() {
	ScriptRunner::Init();
    lua_register(L,"find_id",find_id);
    lua_register(L,"save_id",save_id);
    lua_register(L,"make_code",make_code);
    lua_register(L,"push_stack",push_stack);
    lua_register(L,"pop_stack",pop_stack);
    lua_register(L,"now_pointer",now_pointer);
    lua_register(L,"write_code",write_code);
    lua_register(L,"exit",exitfunc);
}

