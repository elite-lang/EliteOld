/* 
* @Author: sxf
* @Date:   2014-10-02 20:47:00
* @Last Modified by:   sxf
* @Last Modified time: 2014-10-04 19:24:53
*/
#include "Lex.h"
#include <iostream>
#include <fstream>
#include "RuleManager.h"
using namespace std;

Lex::Lex() {
	ruleManager = new RuleManager();
}

Lex::~Lex() {

}

Lex::Lex(const wchar_t* pData) {
	setData(pData);
	ruleManager = new RuleManager();
}

Token* Lex::Read() {
    LexToken* t = ruleManager->Read();
    Token* token = new Token();
    token->pToken = new CHAR[t->data.size()+1];
    wcscpy(token->pToken,t->data.c_str());
    token->type = t->type;
    token->row_num = t->row_num;
    token->col_num = t->col_num;
    delete t;
    return token;
}

void Lex::Init(const wchar_t* pData){
    if (pData != NULL)
	setData(pData);
    
    // init the lex system
    ruleManager->combineAllDFA();
    ruleManager->InitCore(pData);
}

int Lex::AddRule(const wchar_t* pName,const wchar_t* pattern){
	return this->ruleManager->AddRule(pName,pattern);
} 

bool Lex::DeleteRule(const wchar_t* pName){
// 	return this->ruleManager->DeleteRule(pName);
}

bool Lex::DeleteRule(int id){
// 	return this->ruleManager->DeleteRule(id);
}

bool Lex::ChangeRule(const wchar_t* pName, const wchar_t* pattern){
// 	return this->ruleManager->ChangeRule(pName, pattern);
}

bool Lex::ChangeRule(int id, const wchar_t* pattern){
// 	return this->ruleManager->ChangeRule(id, pattern);
} 

int Lex::FindRule(const wchar_t* pName){
    return this->ruleManager->FindRule(pName);
}

const wchar_t* Lex::getData(){
	return this->pData;
}

void Lex::setData(const wchar_t* pData){
	this->pData = pData;
}

int Lex::getRuleSize() {
    ruleManager->getRuleSize();
}

const wchar_t* Lex::getRule(int id) {
    const Rule& r = ruleManager->getRule(id);
    return r.name.c_str();
}

bool Lex::ReadConfig(const char* path) {
    wfstream cfgFile;  
    cfgFile.open(path);//打开文件      
    if(!cfgFile.is_open())  
    {  
        printf("can not open cfg file!\n");
        return false;  
    }
    wchar_t tmp[1000];  
    while(!cfgFile.eof())//循环读取每一行  
    {  
        cfgFile.getline(tmp,1000);//每行读取前1000个字符，1000个应该足够了  
        wstring line(tmp);  
        size_t pos = line.find('=');//找到每行的“=”号位置，之前是key之后是value  
        if(pos==string::npos) return false;  
        wstring key = line.substr(0,pos);//取=号之前  
        wstring value = line.substr(pos + 1);
        printf("%S = %S\n",key.c_str(), value.c_str());
        AddRule(key.c_str(), value.c_str());
    }  
    
    return true;  
}
