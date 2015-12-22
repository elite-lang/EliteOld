/* 
* @Author: sxf
* @Date:   2015-12-21 20:39:08
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 09:17:53
*/

#include "DebugMsg.h"
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

void setDebugFilePath(const char* path) {

}


/**
 * @brief 判断是否Debug模式
 */
bool isDebug() {

}


/**
 * @brief 获取解析器的debug输出文件流
 */
std::ostream parser_dbg() {

}

void parser_close() {

}


/**
 * @brief 获取词法分析器的debug文件输出流
 */
std::ostream lex_dbg() {

}

void lex_close() {

}



DebugMsg_Private* DebugMsg::getInstance() {
	if (instance == NULL) 
		instance = new DebugMsg_Private();
	return instance;
}

DebugMsg_Private* DebugMsg::instance = NULL;