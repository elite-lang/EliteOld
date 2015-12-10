/* 
* @Author: sxf
* @Date:   2014-10-02 20:30:46
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-07 11:49:03
*/
#include "LexInterface.h"
#include <stdio.h>

#ifndef LEX_H
#define LEX_H

class RuleManager;

/****
* Lex is the main controller for the system
****/
class Lex : public LexInterface
{
public:
	Lex();
	~Lex();

	// get the next token ,if it is done ,will return NULL
	// it may throw exception, please try and catch it 
    virtual Token* Read();

	// initialize the Lex system, must be called before Read Token, it can also set the pData
	virtual void Init(const char* pData = NULL);

	// read the config, you need to call it manually before init system, it will find the lex.cfg at the ./ path
	bool ReadConfig(const char* path = NULL);

	// add a new Lex rule
	int AddRule(const char* pName, const char* pattern); // return the rule's id

	// find the rule, will return the id of it.
	int FindRule(const char* pName);

	// find the rule name
    virtual const char* getRule(int id);

    // get the rules sum
    virtual int getRuleSize();

	// ============================================
	// getter and setter 
	// ============================================
	const char* getData();
	virtual void setData(const char* pData);

private:

	// ============================================
	// member variable
	// ============================================
	
	const char* pData = NULL; //all the data need to be splited

	int pointer = 0; //pointer for the data, it's always point to the next char need to be scan.

	RuleManager* ruleManager; // used to manage the rules
	//if the class is declared before defined, use it must be a pointer.
	//because the complier didn't know how much memory it need to allocated.

};

#endif //LEX_H
