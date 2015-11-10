/* 
* @Author: sxf
* @Date:   2015-11-05 17:14:18
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-05 17:23:17
*/

#include <stdio.h>
#include "oolua/oolua.h"

void say(char const* input) {
	printf("%s\n", input);
}

OOLUA_CFUNC(say, l_say)

void hello_minimalist_function() {
    using namespace OOLUA; //NOLINT(build/namespaces)
    Script vm;
    set_global(vm, "say", l_say);
    run_chunk(vm, "say('Hello Lua')");
}

int main(int argc, char const *argv[])
{
	hello_minimalist_function();
	return 0;
}