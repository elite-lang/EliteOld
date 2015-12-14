/* 
* @Author: sxf
* @Date:   2015-11-04 10:16:06
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-04 22:06:49
*/
#include "charsetdetect.h"
#include "stdio.h"
#include "exiconv.h"

#define BUFFER_SIZE 4096
#define CHAR uint32_t

int main(int argc, const char * argv[]) {
    FILE* f = fopen(argv[1], "r");
    size_t outsize;
    echar_t* str = autoreadfile(f, &outsize);
    printf("echar_len = %d\n", estrlen(str));
    char* utf8_str = conv2utf8(str, &outsize);
    printf("utf8:%s\n", utf8_str);
    fclose(f);
    return 0;
}