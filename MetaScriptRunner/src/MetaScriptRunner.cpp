/* 
* @Author: sxf
* @Date:   2015-11-07 13:52:20
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-11 20:58:18
*/

#include "MetaScriptRunner.h"
#include "oolua/oolua.h"


extern void InitMetaAPI(lua_State*);

void MetaScriptRunner::Init() {
	L = *vm;
	ScriptRunner::Init();
	InitMetaAPI(L);
}

MetaScriptRunner* MetaScriptRunner::Create() {
	return new MetaScriptRunner();
}

MetaScriptRunner::MetaScriptRunner() {
	vm = new OOLUA::Script();
}

MetaScriptRunner::~MetaScriptRunner() {
	delete vm;
}

Node* MetaScriptRunner::getRoot() {
	return root;
}

extern Node* node_root;

void MetaScriptRunner::Finished() {
	root = node_root;
}


bool MetaScriptRunner::run_file (std::string const &filename) {
	vm->run_file(filename);
}
bool MetaScriptRunner::load_file (std::string const &filename) {
	vm->load_file(filename);
}
bool MetaScriptRunner::load_chunk (std::string const &chunk) {
	vm->load_chunk(chunk);
}
bool MetaScriptRunner::run_chunk (std::string const &chunk) {
	vm->run_chunk(chunk);
}