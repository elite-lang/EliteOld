#include "LexInterface.h"
#include <vector>
#include <string>

using namespace std;

#ifndef SCRIPTRUNNER_H
#define SCRIPTRUNNER_H

class Grammer_Node;
class Node;


/**
 * @brief 脚本解析器类(其实这个类应该放到MetaScriptRunner中)
 */
class ScriptRunner
{
public:
    virtual void Init(); // 重载时注意初始化父类
    virtual int MakeEnv(const char*, Grammer_Node*);
    virtual int MakeNewLuaTable(Token* t);
    virtual int Run(int&, char*, Grammer_Node*);
    virtual void Finished(); // 可重载作为回调信号
    virtual void ClearEnv();
    virtual void RunLine(const char* line); // 已在本类实现
    virtual Node* getRoot(); // 仅支持后端为RedApple的宏翻译系统，其余系统返回NULL
    virtual vector< pair<string, Grammer_Node*> >& getEnv();
    virtual struct lua_State* getLuaState();

    bool isRunMeta() { return runMeta; }
    void setRunMeta(bool b) { runMeta = b; }

protected:
    ScriptRunner();
    ~ScriptRunner();
    char* addFunction(char* data);
    struct lua_State* L = NULL;
    vector< pair<string, Grammer_Node*> > env;
    bool runMeta;
};

#endif // SCRIPTRUNNER_H
