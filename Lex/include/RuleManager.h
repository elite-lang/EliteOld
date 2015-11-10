/* 
* @Author: sxf
* @Date:   2014-10-02 23:31:33
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 16:42:12
*/

#include <string>
#include <vector>
#include <map>
#include "EquivalenceClass.h"
#include "DFA.h"
#include "DFACore.h"

#ifndef RULEMANAGER_H
#define RULEMANAGER_H

struct Rule{
	Glib::ustring name;
	Glib::ustring pattern;
	DFA* dfa;
	bool operator==(Glib::ustring obj){
		return name==obj;
	}
};


/****
* It's a manager for rules and regex.
****/
class RuleManager
{
public:
	RuleManager();
	~RuleManager();
	
	// add a new Lex rule
    int AddRule(const char*,const char*); // return the rule's id

	// find the rule, will return the id of it.
    int FindRule(const char*);
	
    Token* Read();

	// when you change the Rule, you should run it manually
	DFA* combineAllDFA();

    void InitCore(const char*);
	
	// ====setter and getter =============
    int getRuleSize() { ruleList.size(); }
	DFA* getMainDFA();
    const Rule getRule(int id) { return ruleList.at(id); }
    
private:
	std::vector<Rule> ruleList;
	EquivalenceClass* pEClass;
	// Main dfa for all dfa combine to one
	DFA* mainDFA;
    DFACore* core;
	int testin(vector< int > newvec, vector< vector< int > > statelist);
	bool testequal(vector< int > , vector< int > );
    void addStopState(vector<int>&,int);
	/*
	// add a new Lex rule
	int AddRule(std::wstring pName, std::wstring pattern); // return the rule's id

	// delete a Lex rule
	bool DeleteRule(std::wstring pName);
	bool DeleteRule(int id); //also can use the id to delete it.

	// change a Lex rule
	bool ChangeRule(std::wstring pName, std::wstring pattern);
	bool ChangeRule(int id,std::wstring pattern);

	
	*/
};

#endif //RULEMANAGER_H
