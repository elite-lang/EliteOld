/* 
* @Author: sxf
* @Date:   2015-11-07 13:52:20
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-07 15:47:08
*/

#include "MetaScriptRunner.h"


extern void InitMetaAPI();

void MetaScriptRunner::Init() {
	L = vm();
	ScriptRunner::Init();
	InitMetaAPI(L);
}

MetaScriptRunner* MetaScriptRunner::Create() {
	return new MetaScriptRunner();
}

MetaScriptRunner::MetaScriptRunner() {

}

MetaScriptRunner::~MetaScriptRunner() {

}


bool run_file (std::string const &filename) {
	vm.run_file(filename);
}
bool load_file (std::string const &filename) {
	vm.load_file(filename);
}
bool load_chunk (std::string const &chunk) {
	vm.load_chunk(chunk);
}
bool run_chunk (std::string const &chunk) {
	vm.run_chunk(chunk);
}