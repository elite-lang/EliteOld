#include "Grammer_Node.h"
#include "ScriptRunner.h"
#include <string.h>
#include "lua.hpp"

static ScriptRunner* runner;
static int cachecode;
static Grammer_Node* rootnode;

static int CallFunc(lua_State * L) {
    auto& env = runner->getEnv();
    for (auto p : env) {
        lua_rawgeti(L,LUA_REGISTRYINDEX, p.second->lua_data);
    }
    lua_call(L, env.size(), 1);
    return luaL_ref(L,LUA_REGISTRYINDEX);//获得引用的索引,并pop当前栈顶
}

static int getLuaFunc(lua_State * L)
{
//    lua_pushstring(L, "hello");
    lua_pushvalue(L,-1);//复制栈顶
    cachecode = luaL_ref(L,LUA_REGISTRYINDEX);//获得引用的索引,并pop当前栈顶
    rootnode->lua_data = CallFunc(L);
    return 0;
}



ScriptRunner::ScriptRunner()
{
    
}

ScriptRunner::~ScriptRunner() {
    lua_close(L);
}

void ScriptRunner::Init() {
    if (L == NULL) {
        L = luaL_newstate();
        luaL_openlibs(L);
        lua_register(L,"Cfunc",getLuaFunc);
    } else {
        lua_register(L,"Cfunc",getLuaFunc);
    }
}

void ScriptRunner::Finished() {

}

Node* ScriptRunner::getRoot() {
    return NULL;
}

int ScriptRunner::MakeEnv(const char* name, Grammer_Node* node) {
    env.push_back(make_pair(name,node));
}

int ScriptRunner::MakeNewLuaTable(Token* t) {
    lua_newtable(L);
    lua_pushstring(L,t->pToken);
    lua_setfield(L,-2,"val");
    lua_pushinteger(L,t->type);
    lua_setfield(L,-2,"type");
    return luaL_ref(L,LUA_REGISTRYINDEX);//获得引用的索引,并pop当前栈顶
}

char* ScriptRunner::addFunction(char* data) {
    char* func;
    string params;
    int len = 0; bool isfirst = true;
    for (auto p : env) {
        const char* name = p.first.c_str();
        int namelen = strlen(name);
        if (isfirst) isfirst = false; else { params.push_back(','); ++len; }
        params.append(name);
        len += namelen;
    }

    int codelen = strlen(data);
    len += codelen; len += 30;
    func = new char[len];
    sprintf(func,"Cfunc(function(%s) %s end)\n",params.c_str(),data);
    return func;
}


void ScriptRunner::RunLine(const char* line) {
    int size;
    const char* buff = line + 1;
    int error = luaL_loadbuffer(L, buff, size ,"chunk") //加载当前script
                | lua_pcall(L, 0, 0, 0); // 巧妙的利用或运算符，前面若成功返回0，则执行后面的
    if (error) {
        printf("%s", lua_tostring(L, -1));
        lua_pop(L, 1);/* pop error message from the stack */
        return;
    }
}

int ScriptRunner::Run(int& code, char* data, Grammer_Node* node) {
    int error;
    runner = this; rootnode = node;
    printf("LUA STACK: %d\n",lua_gettop(L));
    if (code == 0) {
        char* buff = addFunction(data);
        printf("load script: %s",buff);
        error = luaL_loadbuffer(L, buff, strlen(buff) ,"chunk") //加载当前script
                | lua_pcall(L, 0, 0, 0); // 巧妙的利用或运算符，前面若成功返回0，则执行后面的
        delete[] buff;
        if (error) goto LUA_ERROR;
        code = cachecode; // 将C函数处理得到的缓存代码返回
    } else {
        printf("run script: ");
        lua_rawgeti(L,LUA_REGISTRYINDEX, code);
        node->lua_data = CallFunc(L);
    }

    return 0;
LUA_ERROR:
    printf("%s", lua_tostring(L, -1));
    lua_pop(L, 1);/* pop error message from the stack */
    return -1;
}

lua_State* ScriptRunner::getLuaState() { 
    return L;
}

void ScriptRunner::ClearEnv() { 
    if (env.size() != 0) env.clear(); 
}

vector< pair<string, Grammer_Node*> >& ScriptRunner::getEnv() { 
    return env; 
}