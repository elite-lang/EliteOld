/* 
* @Author: sxf
* @Date:   2014-10-02 20:30:46
* @Last Modified by:   sxf
* @Last Modified time: 2014-10-03 22:59:43
*/
#include "LexInterface.h"
#include <string>
using namespace std;

#ifndef LEX_H
#define LEX_H

#define NULL 0
#define EOF -1

//it's a token for return
struct LexToken
{
    wstring data;
    int type; // when type == -1 means EOF
    int col_num;
    int row_num;
};


class RuleManager;

/****
* Lex is the main controller for the system
****/
class Lex : public LexInterface
{
public:
	Lex();
	~Lex();

	// data is the buffer pointer, isCopy means to copy the buffer for a new one
	Lex(const wchar_t* pData);

	// get the next token ,if it is done ,will return NULL
	// it may throw exception, please try and catch it 
    virtual Token* Read();

	// initialize the Lex system, must be called before Read Token, it can also set the pData
	void Init(const wchar_t* pData = NULL);

	// read the config, you need to call it manually before init system, it will find the lex.ini at the ./ path
	bool ReadConfig(const char* path = NULL);

	// add a new Lex rule
	int AddRule(const wchar_t* pName, const wchar_t* pattern); // return the rule's id

	// delete a Lex rule
	bool DeleteRule(const wchar_t* pName);
	bool DeleteRule(int id); //also can use the id to delete it.

	// change a Lex rule
	bool ChangeRule(const wchar_t* pName, const wchar_t* pattern);
	bool ChangeRule(int id, const wchar_t* pattern);

	// find the rule, will return the id of it.
	int FindRule(const wchar_t* pName);

	// find the rule name
    virtual const wchar_t* getRule(int id);

    // get the rules sum
    virtual int getRuleSize();

	// ============================================
	// getter and setter 
	// ============================================
	const wchar_t* getData();
	void setData(const wchar_t* pData);

private:

	// ============================================
	// member variable
	// ============================================
	
	const wchar_t* pData = NULL; //all the data need to be splited

	int pointer = 0; //pointer for the data, it's always point to the next char need to be scan.

	RuleManager* ruleManager; // used to manage the rules
	//if the class is declared before defined, use it must be a pointer.
	//because the complier didn't know how much memory it need to allocated.

};

#endif //LEX_H
