/* 
* @Author: sxf
* @Date:   2015-04-17 10:05:26
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-28 13:58:28
*/


#ifndef BNF_PARSER_H
#define BNF_PARSER_H

#include "State.h"
#include "VMap.h"
#include <map>

using namespace std;


class BNFParser {

public:

	State* Analysis(const char* filename);

	void NowLeft();
	void NowRight();
	void AddToken(const char* token);
	void MakePrecedence(VMap& vmap);
	int getPrecedence(int id);
	bool getAssociativity(int id);
	// for debug
	void printTree();

private:
	State* state_root;

	// 优先级表，从0开始，为最小有限，数字越大，优先级越高
	std::map<string, int> precedence_map; 

	// 结合性表，true为左结合，false为右结合
	std::map<string, bool> associativity_map; 

	std::map<int, int> id_precedence_map; 
	std::map<int, bool> id_associativity_map; 

	int now_precedence;
	bool now_associativity;
	
	// for debug
	void printNode(State* s,int d);
};


#endif // BNF_PARSER_H
