/* 
* @Author: sxf
* @Date:   2015-11-07 13:52:20
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 17:42:32
*/

#include "MetaScriptRunner.h"
#include "oolua/oolua.h"
#include "PackageLoader.h"

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
	if (loader != NULL) delete loader;
}

void MetaScriptRunner::setUpLoader(const string& path) {
	loader = new PackageLoader(path, this);
	loader->FindAll();
	loader->LoadDefault();
}

Node* MetaScriptRunner::getRoot() {
	return root;
}

extern Node* node_root;

void MetaScriptRunner::Finished() {
	printf("Great! Finished!\n");
	root = node_root;
}


bool MetaScriptRunner::run_file (std::string const &filename) {
	return vm->run_file(filename);
}
bool MetaScriptRunner::load_file (std::string const &filename) {
	return vm->load_file(filename);
}
bool MetaScriptRunner::load_chunk (std::string const &chunk) {
	return vm->load_chunk(chunk);
}
bool MetaScriptRunner::run_chunk (std::string const &chunk) {
	return vm->run_chunk(chunk);
}