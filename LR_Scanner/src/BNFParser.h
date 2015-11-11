/* 
* @Author: sxf
* @Date:   2015-04-17 10:05:26
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-10 19:47:43
*/


#ifndef BNF_PARSER_H
#define BNF_PARSER_H

#include "State.h"

class BNFParser {

public:

    State* Analysis(const char* filename);

    // for debug
    void printTree();

private:
    State* state_root;

	// for debug
	void printNode(State* s,int d);
};


#endif // BNF_PARSER_H
