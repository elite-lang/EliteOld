#include "Preprocessor.h"
#include <cctype>

using namespace std;


const std::string& Preprocessor::genCode() {
    std::string script;

    std::string::const_iterator b = input.begin();
    std::string::const_iterator e = input.end();
    bool is_script = false;
    if (*b == '#') { ++b; is_script = true; }
    for (auto p = input.begin(); p != input.end(); ++p) {
        if (*p == '\n') {
            if (is_script) { e = p+1; script.append(b, e); }
            if (!is_script && *(p+1) == '#') {
                e = p+1;
                int k = add_const_str(b, e);
                script += "__loadStr(";
                script += to_string(k);
                script += ");\n";
            }
            if (is_script) b=p+1;
            if (*(p+1) == '#') { b=p+1; ++b; is_script = true; }
            else { is_script = false; }
        }
    }
    code_string = script;
    return code_string;
}

const std::string& Preprocessor::runCode() {
    lua_pushglobaltable(L);
    lua_pushlightuserdata(L, this);
    lua_setfield(L, -2, "__preprocessor");

    int error = luaL_loadbuffer(L, code_string.c_str(), code_string.size() ,"chunk") //加载当前script
                | lua_pcall(L, 0, 0, 0); // 巧妙的利用或运算符，前面若成功返回0，则执行后面的

    if (error) {
        printf("====== ERROR! ======\n");
        printf("%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);/* pop error message from the stack */
        return output;
    }

    return output;
}


int Preprocessor::add_const_str(
    std::string::const_iterator p, std::string::const_iterator q) {
    string str(p, q);
    lua_pushstring(L, str.c_str());
    return luaL_ref(L, LUA_REGISTRYINDEX);
}

static std::string add_lua_call(const char*& p) {
    auto b = p;
    while (isalpha(*p)||isdigit(*p)||(*p=='_')) ++p;
    if (*p == '(') {
        for (int k = 1; k != 0; ++p) {
            if (*p == '(') ++k;
            if (*p == ')') --k;
        }
    }
    return string(b, p-b);
}

static int lua_echo (lua_State *L) {
    int n = lua_gettop(L);  /* number of arguments */

    // get the pointer for Class Preprocess
    lua_pushglobaltable(L);
    lua_getfield(L, -1, "__preprocessor");
    Preprocessor* p = (Preprocessor*)lua_topointer(L, -1);
    lua_pop(L, 1);

    lua_getglobal(L, "tostring");
    for (int i=1; i<=n; i++) {
        const char *s;
        size_t l;
        lua_pushvalue(L, -1);  /* function to be called */
        lua_pushvalue(L, i);   /* value to print */
        lua_call(L, 1, 1);
        s = lua_tolstring(L, -1, &l);  /* get result */
        if (s == NULL)
            return luaL_error(L, "'tostring' must return a string to 'print'");
        if (i>1) p->output += '\t';
        string data(s, l);
        p->output += data;

        lua_pop(L, 1);  /* pop result */
    }
    p->output += '\n';


    return 0;
}


static int lua_loadStr(lua_State* L) {
    int n = lua_gettop(L);  /* number of arguments */

    int id = lua_tonumber(L, -1);
    lua_rawgeti(L, LUA_REGISTRYINDEX, id);
    const char* str = lua_tostring(L, -1);
    // get the pointer for Class Preprocess
    lua_pushglobaltable(L);
    lua_getfield(L, -1, "__preprocessor");
    Preprocessor* pp = (Preprocessor*)lua_topointer(L, -1);
    lua_pushglobaltable(L);
    lua_getfield(L, -1, "Escape");
    bool b = lua_toboolean(L, -1);
    lua_pop(L, 2);

    if (b == false)
        pp->output += str;
    else {
        for (const char* p = str; p != 0; ++p) {
            if (*p != '$') pp->output += *p;
            else {
                lua_pushcfunction(L, lua_echo);
                string script = add_lua_call(p);
                int error = luaL_loadbuffer(L, script.c_str(), script.size() ,"chunk") //加载当前script
                            | lua_pcall(L, 0, 0, 0); // 巧妙的利用或运算符，前面若成功返回0，则执行后面的

                if (error | lua_pcall(L, 0, 0, 0)) {
                    printf("====== LUA ERROR! ======\n");
                    printf("%s\n", lua_tostring(L, -1));
                    lua_pop(L, 1);/* pop error message from the stack */
                    return 0;
                }
            }
        }
    }

    lua_pop(L, 3);
    return 0;
}

Preprocessor::Preprocessor (const std::string& input, lua_State* L)
    : input(input) {
    this->L = L;
    lua_register(L, "__loadStr", lua_loadStr);
    lua_register(L, "echo", lua_echo);

    lua_pushglobaltable(L);
    lua_pushboolean(L, 0);
    lua_setfield(L, -2, "Escape");
}

Preprocessor::~Preprocessor () {

}
