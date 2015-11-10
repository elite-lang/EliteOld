/* 
* @Author: sxf
* @Date:   2014-10-02 20:47:00
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 20:13:14
*/
#include "Lex.h"
#include <iostream>
#include <fstream>
#include "glibmm.h"
#include "RuleManager.h"
using namespace std;

Lex::Lex() {
	ruleManager = new RuleManager();
}

Lex::~Lex() {

}

Lex::Lex(const char* pData) {
	setData(pData);
	ruleManager = new RuleManager();
}

Token* Lex::Read() {
    return ruleManager->Read();
}

void Lex::Init(const char* pData){
    if (pData != NULL)
	setData(pData);
    
    // init the lex system
    ruleManager->combineAllDFA();
    ruleManager->InitCore(pData);
}

int Lex::AddRule(const char* pName,const char* pattern){
	return this->ruleManager->AddRule(pName,pattern);
} 

int Lex::FindRule(const char* pName){
    return this->ruleManager->FindRule(pName);
}

const char* Lex::getData(){
	return this->pData;
}

void Lex::setData(const char* pData){
	this->pData = pData;
}

int Lex::getRuleSize() {
    ruleManager->getRuleSize();
}

const char* Lex::getRule(int id) {
    const Rule& r = ruleManager->getRule(id);
    return r.name.c_str();
}

bool Lex::ReadConfig(const char* path) {
    fstream cfgFile;  
    cfgFile.open(path);//打开文件      
    if(!cfgFile.is_open())  
    {  
        printf("can not open cfg file!\n");
        return false;  
    }
    char tmp[1000];  
    while(!cfgFile.eof())//循环读取每一行  
    {  
        cfgFile.getline(tmp,1000);//每行读取前1000个字符，1000个应该足够了  
        Glib::ustring line(tmp);  
        size_t pos = line.find('=');//找到每行的“=”号位置，之前是key之后是value  
        if(pos==string::npos) return false;  
        Glib::ustring key = line.substr(0,pos);//取=号之前  
        Glib::ustring value = line.substr(pos + 1);
        // printf("%s = %s\n",key.c_str(), value.c_str());
        AddRule(key.c_str(), value.c_str());
    }  
    
    return true;  
}
