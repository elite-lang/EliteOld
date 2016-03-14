#include "Preprocessor.h"

using namespace std;

Preprocessor::Preprocessor (const std::string& input, lua_State* L)
    : input(input) {
    this->L = L;
}

Preprocessor::~Preprocessor () {

}


const std::string& Preprocessor::genCode() {
    std::string script;

    std::string::const_iterator b = input.begin();
    std::string::const_iterator e = input.end();
    bool is_script = false;
    if (*b == '#') { ++b; is_script = true; }
    for (auto p = input.begin(); p != input.end(); ++p) {
        if (*p == '\n') {
            e = (++p);
            if (is_script) script.append(b, e);
            else {
                int p = add_const_str(b, e);
                script += "__loadStr(";
                script += p;
                script += ");";
            }
            b = e;
            if (*b == '#') { ++b; is_script = true; }
            else is_script = false;
            if (b == input.end()) break;
        }

        if (*p == '$' && !is_script) {

        }
    }


    return code_string;
}

const std::string& Preprocessor::runCode() {
    lua_pushlightuserdata(L, this);
    lua_setfield(L, LUA_REGISTRYINDEX, "__preprocessor");

    return output;
}


int Preprocessor::add_const_str(
    std::string::const_iterator p, std::string::const_iterator q) {
    string str(p, q);

    lua_pushstring(L, str.c_str());
    return luaL_ref(L, LUA_REGISTRYINDEX);
}


static int loadStr(lua_State* L) {
    int id = lua_tonumber(L, -1);
    lua_rawgeti(L, LUA_REGISTRYINDEX, id);
    const char* str = lua_tostring(L, lua_tonumber(L, -1));

    // get the pointer for Class Preprocess
    lua_getfield(L, LUA_REGISTRYINDEX, "__preprocessor");
    Preprocessor* p = (Preprocessor*)lua_topointer(L, -1);
    p->output += str;

    lua_pop(L, 3);
    return 0;
}

static int lua_echo (lua_State *L) {
  int n = lua_gettop(L);  /* number of arguments */

  // get the pointer for Class Preprocess
  lua_getfield(L, LUA_REGISTRYINDEX, "__preprocessor");
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
