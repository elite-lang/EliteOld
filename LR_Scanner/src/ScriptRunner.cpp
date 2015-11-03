#include "ScriptRunner.h"
#include <string>

static ScriptRunner* runner;
static int cachecode;
static Grammer_Node* rootnode;

static int CallFunc(lua_State * L) {
    vector< pair<BNFCHAR*, Grammer_Node*> >& env = runner->getEnv();
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
    }   
}

void ScriptRunner::Finished() {

}

int ScriptRunner::MakeEnv(BNFCHAR* name, Grammer_Node* node) {
    env.push_back(make_pair(name,node));
}

int ScriptRunner::MakeNewLuaTable(Token* t) {
    lua_newtable(L);
    // TODO: 这里需要进行Unicode支持，先暂时使用简单的转换函数
    int size;
    char* str = WCharToChar(t->pToken, size);
    lua_pushstring(L,str);
    lua_setfield(L,-2,"val");
    lua_pushinteger(L,t->type);
    lua_setfield(L,-2,"type");
    delete[] str;
    return luaL_ref(L,LUA_REGISTRYINDEX);//获得引用的索引,并pop当前栈顶
}

char* ScriptRunner::addFunction(BNFCHAR* data) {
    char* func;
    string params;
    int len = 0; bool isfirst = true;
    for (auto p : env) {
        char* name = p.first;
        int namelen = strlen(name);
        if (isfirst) isfirst = false; else { params.push_back(','); ++len; }
        params.append(name);
        len += namelen;
        // delete[] name; // 我不知道为何这里要删除这个地方不能删除
    }

    int codelen = strlen(data);
    len += codelen; len += 30;
    func = new char[len];
    sprintf(func,"Cfunc(function(%s) %s end)\n",params.c_str(),data);
    return func;
}



char* ScriptRunner::WCharToChar(wchar_t* data,int& size) {
    int len = STRLEN(data);
    char* newdata = new char[len+1];
    int i = 0;
    while (data[i] != 0) {
        if (data[i] < 255)
        newdata[i] = (char)data[i];
        ++i;
    }
    newdata[i] = 0;
    size = i;
    return newdata;
}

int ScriptRunner::Run(int& code, BNFCHAR* data, Grammer_Node* node) {
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

vector< pair<BNFCHAR*, Grammer_Node*> >& ScriptRunner::getEnv() { 
    return env; 
}