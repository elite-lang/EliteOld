/* 
* @Author: sxf
* @Date:   2015-12-21 20:39:08
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 15:32:10
*/

#include "DebugMsg.h"
#include <iostream>
#include <string>

using namespace std;

class DebugMsg_Private
{
public:
	string dbg_file_path;
	bool is_debug_mode;

	fstream parser_dbg_fs;
	fstream lex_dbg_fs;
};

void DebugMsg::setDebugFilePath(const char* path) {
	auto& debug_out_path = getInstance()->dbg_file_path;
	auto& is_debug_mode = getInstance()->is_debug_mode;
	if (path != NULL) {
        debug_out_path = path;
        if (debug_out_path.length() != 0)
            is_debug_mode = true;
    } else {
        is_debug_mode = false;
        debug_out_path = "";
    }
}


/**
 * @brief 判断是否Debug模式
 */
bool DebugMsg::isDebug() {
	return getInstance()->is_debug_mode;
}


/**
 * @brief 获取解析器的debug输出文件流
 */
std::ostream& DebugMsg::DebugMsg::parser_dbg() {
	auto& fs = getInstance()->parser_dbg_fs;
	if(!fs.is_open()) {
		fs.open(getInstance()->dbg_file_path+"/parser_dbg.log", std::ios::out);
	}
	return fs;
}

void DebugMsg::parser_close() {
	auto& fs = getInstance()->parser_dbg_fs;
	fs.close();
}


/**
 * @brief 获取词法分析器的debug文件输出流
 */
std::ostream& DebugMsg::lex_dbg() {
	auto& fs = getInstance()->lex_dbg_fs;
	if(!fs.is_open()) {
		fs.open(getInstance()->dbg_file_path+"/lex_dbg.log", std::ios::out);
		return fs;
	}
	return fs;
}

void DebugMsg::lex_close() {
	auto& fs = getInstance()->lex_dbg_fs;
	fs.close();
}



DebugMsg_Private* DebugMsg::getInstance() {
	if (instance == NULL) 
		instance = new DebugMsg_Private();
	return instance;
}

DebugMsg_Private* DebugMsg::instance = NULL;