/*
* @Author: sxf
* @Date:   2015-12-16 12:02:18
* @Last Modified by:   sxf
* @Last Modified time: 2016-03-05 17:01:18
*/

#include <gtest/gtest.h>
#include "Preprocessor.h"

#include <iostream>
#include <fstream>
using namespace std;

static std::string fileReader(const char* path) {
    std::ifstream t(path, std::ios::binary);
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	            std::istreambuf_iterator<char>());
    return str;
}


#define __PP_TEST__(name) TEST(PP_##name, name)

__PP_TEST__(Construction)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	string data = fileReader("../../test/t1.ecode");
	cout << data << endl << endl;
	Preprocessor pp(data, L);
	cout << "----------------------" << endl;
	cout << pp.genCode() << endl << endl;
	lua_close(L);
}


__PP_TEST__(Run)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	string data = fileReader("../../test/t1.ecode");
	Preprocessor pp(data, L);
	cout << pp.genCode() << endl << endl;
	cout << "---------------------" << endl;
	cout << pp.runCode() << endl << endl;

	lua_close(L);
}
