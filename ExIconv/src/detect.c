/* 
* @Author: sxf
* @Date:   2015-11-04 15:34:23
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-04 20:23:24
*/

#include "exiconv.h"
#include "charsetdetect.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
extern const char*
encodedetect (const char* data) {
	assert(data != NULL);
	csd_t csd = csd_open();
    if (csd == (csd_t)-1) {
        printf("csd_open failed\n");
        return NULL;
    }

    int size = strlen(data);
    int result = csd_consider(csd, data, size);
    if (result < 0) 
        return NULL;
    return csd_close(csd);
}


extern const char*
fileencodedetect (FILE* f) {
	assert(f != NULL);
	csd_t csd = csd_open();
    if (csd == (csd_t)-1) {
        printf("csd_open failed\n");
        return NULL;
    }
    int sumsize = 0;
    int size; const int BUFFER_SIZE = 1024;
    char buf[BUFFER_SIZE]; 
    memset(buf, sizeof(buf), 0);
    while ((size = fread(buf, 1, BUFFER_SIZE, f)) != 0) {
    	sumsize += size;
        int result = csd_consider(csd, buf, size);
        if (result < 0) {
            printf("csd_consider failed\n");
            return NULL;
        } else if (result > 0) {
            // Already have enough data
            break;
        }
    }
    fseek(f, -sumsize, SEEK_CUR);
    return csd_close(csd);
}