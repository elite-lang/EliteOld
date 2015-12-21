/* 
* @Author: sxf
* @Date:   2015-12-21 20:39:08
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-21 21:37:08
*/

#include "DebugMsg.h"
#include <fstream>
#include <iostream>

using namespace std;

class DebugMsg_Private
{
public:
	DebugMsg_Private() {

	}
	~DebugMsg_Private() {

	}
};

DebugMsg_Private* DebugMsg::getInstance() {
	if (instance == NULL) 
		instance = new DebugMsg_Private();
	return instance;
}

DebugMsg_Private* DebugMsg::instance = NULL;