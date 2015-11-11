#include "LexInterface.h"
#include <vector>
#include <string>

using namespace std;

#ifndef SCRIPTRUNNER_H
#define SCRIPTRUNNER_H

class Grammer_Node;
class Node;

class ScriptRunner
{
public:
    virtual void Init();
    virtual int MakeEnv(const char*, Grammer_Node*);
    virtual int MakeNewLuaTable(Token* t);
    virtual int Run(int&, char*, Grammer_Node*);
    virtual void Finished();
    virtual void ClearEnv();
    virtual void RunLine(const char* line);
    virtual Node* getRoot(); // 仅支持后端为RedApple的宏翻译系统，其余系统返回NULL
    virtual vector< pair<string, Grammer_Node*> >& getEnv();
    virtual struct lua_State* getLuaState();

protected:
    ScriptRunner();
    ~ScriptRunner();
    char* addFunction(char* data);
    struct lua_State* L = NULL;
    vector< pair<string, Grammer_Node*> > env;
};

#endif // SCRIPTRUNNER_H
