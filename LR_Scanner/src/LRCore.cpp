/* 
* @Author: sxf
* @Date:   2015-01-03 18:43:13
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-02 19:48:10
*/

#include "LRCore.h"


Grammer_Node* LRCore::Run(){
    script_runner->Init();
    Token* t = TokenFliter(lex->Read());

    LRStack.push_back(0); // 放入0号根
    int s;
    while (1) {
        s = LRStack.back();
//        printf("Stack Top: %d\n",s);
        switch (table->ACTION(s,t->type)) {
        case 's': {
            Shift(table->GOTO(s,t->type),t);
            t = TokenFliter(lex->Read());
            break;
        }
        case 'r': {
            Grammer_Node* root = ast->NewNode();
            int Vn = Reduce(table->GOTO(s,t->type),root);
            s = LRStack.back();
//            printf("Stack Top: %d, Vn:%d\n",s,Vn);
            Shift(table->GOTO(s,Vn),root);
            break;
        }
        case 'a':
            printf("Accept!\n");
            script_runner->Finished();
            return ast;
        default:
            println(_T("error"));
            //TODO: 需要释放本层资源
            return NULL;
        }
    }

}

char* WCharToChar(const wchar_t* data,int& size) {
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

Token* LRCore::TokenFliter(Token* token) {
    int size;
    int id = vmap->getConst(WCharToChar(token->pToken, size));
    if (id != -1) token->type = id;
    printf("next Token: %d %S\n",token->type,token->pToken);
    return token;
}
    
void LRCore::Shift(int x,Token* t){
    // for debug
    printf("------------------------\n");
    printf("Stack: ");
    for (auto p: LRStack)
    {
        printf("%d ",p);
    }

    printf("Shift: %d\n",x);
    LRStack.push_back(x);
    NodeStack.push(ast->NewNode());
    NodeStack.top()->lua_data = script_runner->MakeNewLuaTable(t);
}

void LRCore::Shift(int x,Grammer_Node* root){

    LRStack.push_back(x);
    NodeStack.push(root);
}

int LRCore::Reduce(int x,Grammer_Node*& root){
    BNF* bnf = bnflist->at(x);

    // for debug
    printf("------------------------\n");
    printf("Stack: ");
    for (auto p: LRStack)
    {
        printf("%d ",p);
    }
    printf("Reduce: %d\n",x+1);

    bnf->print_bnf();



    // 从栈顶弹出对应BNF式元素数个
    int state_sum = bnf->getBNFdata().size();

     // 特殊判断一下epsilon的情况，不进行符号处理
    if (state_sum != 0) {

        vector<Grammer_Node*> tempstack; // 临时符号栈

        for (int i = 0; i < state_sum; ++i) {
            LRStack.pop_back();
            tempstack.push_back(NodeStack.top()); // 这样push后是反向的数组
            NodeStack.pop();
        }
        Grammer_Node* headnode = tempstack.back(); // 获取头节点
        root->AddChildrenNode(headnode); // 设置为子元素
        tempstack.pop_back(); // 从第二个节点开始，若没有则自动跳过
        Grammer_Node* oldnode = headnode; // 滚动的上一个节点

        script_runner->ClearEnv();// 脚本环境清理
        int i = 0;
        for (auto p = tempstack.rbegin(); p != tempstack.rend(); ++p) {
            Grammer_Node* node = *p;
            oldnode->AddBortherNode(node);
            State* state = bnf->getBNFdata()[i];
            if (state->state_var != NULL) {
                // 这里是向LUA中注册变量的部分 MakeEnv
                script_runner->MakeEnv(state->state_var,oldnode);
            }
            oldnode = node;
            ++i;
        }
        State* state = bnf->getBNFdata()[i];
        if (state->state_var != NULL) {
            // 这里是向LUA中注册变量的部分 MakeEnv
            script_runner->MakeEnv(state->state_var,oldnode);
        }

    }
    //TODO: Do the lua script and make the AST
    if (bnf->getScript() != NULL) {
        printf("Script: ");
        printf(bnf->getScript());
        script_runner->Run(bnf->getScriptCode(),bnf->getScript(),root);
    }
    return bnf->getRoot()->id;
}
