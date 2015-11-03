#include "afx.h"
#include "lua.hpp"
#include "LexInterface.h"
#include <vector>

using namespace std;

#ifndef SCRIPTRUNNER_H
#define SCRIPTRUNNER_H

class Grammer_Node;

class ScriptRunner
{
public:
    virtual void Init();
    virtual int MakeEnv(BNFCHAR*, Grammer_Node*);
    virtual int MakeNewLuaTable(Token* t);
    virtual int Run(int&, BNFCHAR*, Grammer_Node*);
    virtual void Finished();
    virtual void ClearEnv();
    virtual vector< pair<BNFCHAR*, Grammer_Node*> >& getEnv();
    virtual lua_State* getLuaState();

protected:
    ScriptRunner();
    ~ScriptRunner();
    char* addFunction(BNFCHAR* data);
    char* WCharToChar(wchar_t* data,int& size);
    lua_State* L = NULL;
    vector< pair<BNFCHAR*, Grammer_Node*> > env;
};

#endif // SCRIPTRUNNER_H
