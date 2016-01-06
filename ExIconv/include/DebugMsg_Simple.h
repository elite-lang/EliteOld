#ifndef DEBUG_MES_SIMPLE
#define DEBUG_MES_SIMPLE

#include "DebugMsg.h"
#include <iostream>

class DebugMsg_Private {
public:
    string dbg_file_path;
    bool is_debug_mode;
};

void DebugMsg::setDebugFilePath(const char* path) {
    getInstance()->is_debug_mode = true;
}

bool DebugMsg::isDebug() {
    return getInstance()->is_debug_mode;
}

std::ostream& DebugMsg::lex_dbg() {
    return std::cout;
}

void DebugMsg::lex_close() {
}

std::ostream& DebugMsg::parser_dbg() {
    return std::cout;
}

void DebugMsg::parser_close() {
}

std::ostream& DebugMsg::red_dbg() {
    return std::cout;
}

void DebugMsg::red_close() {
}


DebugMsg_Private* DebugMsg::getInstance() {
	if (instance == NULL)
		instance = new DebugMsg_Private();
	return instance;
}

DebugMsg_Private* DebugMsg::instance = NULL;



#endif /* end of include guard: DEBUG_MES_SIMPLE */
