/* 
* @Author: sxf
* @Date:   2015-11-04 15:17:26
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-05 08:21:32
*/

#include "iconv.h"
#include "exiconv.h"
#include <malloc.h>
#include <string.h>
#include <assert.h>

extern char* 
echar2code (const echar_t* data, size_t* outsize, const char* encode) {
	assert (data != NULL);
	iconv_t cd = iconv_open (encode, "UTF-32"); // tocode, fromcode
	if ((iconv_t)-1 == cd) { 
		printf("不能从编码 %s 转换到 %s！\n", "UTF-32", encode);
		return NULL; 
	} 
	size_t in_size = sizeof(echar_t) * estrlen(data);
	size_t out_size = in_size;
	size_t malloc_size = out_size;
	char* outbuf = (char*) malloc (out_size);
	char* inptr = (char*) data;
	char* outptr = outbuf;
	// printf("before inbuf = %s, outbuf = %s, inbufbytesleft = %d, outbufbytesleft = %d\n", 
	// 	inptr, outptr, in_size, out_size);
	size_t nconv = iconv (cd, &inptr, &in_size, &outptr, &out_size);
	// printf("after nconv = %d, inbuf = %s, outbuf = %s, inbufbytesleft = %d, outbufbytesleft = %d\n", 
	// 	nconv, inptr, outptr, in_size, out_size);
	if (nconv == -1) {
		printf("%s\n", strerror(errno));
		return NULL; 
	}
	iconv_close (cd);
	*outsize = malloc_size - out_size;
	return outbuf;
}


extern echar_t*
code2echar (const char* data, size_t* outsize, const char* encode) {
	assert (data != NULL);
	iconv_t cd = iconv_open ("UTF-32", encode); // tocode, fromcode
	if ((iconv_t)-1 == cd) { 
		printf("不能从编码 %s 转换到 %s！\n", encode, "UTF-32");
		return NULL; 
	} 
	size_t in_size = strlen(data);
	size_t out_size = sizeof(echar_t) * in_size;
	size_t malloc_size = out_size;
	char* outbuf = (char*) malloc (out_size);
	char* inptr = (char*) data;
	char* outptr = outbuf;
	// printf("before inbuf = %s, outbuf = %s, inbufbytesleft = %d, outbufbytesleft = %d\n", 
	// 	inptr, outptr, in_size, outsize);
	size_t nconv = iconv (cd, &inptr, &in_size, &outptr, &out_size);
	if (nconv == -1) {
		printf("%s\n", strerror(errno));
		return NULL; 
	}
	// printf("after nconv = %d, inbuf = %s, outbuf = %s, inbufbytesleft = %d, outbufbytesleft = %d\n", 
	// 	nconv, inptr, outptr, in_size, outsize);
	iconv_close (cd);
	*outsize = malloc_size - out_size;
	return (echar_t*) outbuf;
}


extern char* 
conv2utf8 (const echar_t* data, size_t* outsize) {
	return echar2code (data, outsize, "UTF-8");
}


extern echar_t*
utf8conv2echar (const char* data, size_t* outsize) {
	return code2echar (data, outsize, "UTF-8");
}


extern echar_t*
autoreadfile (FILE* f, size_t* outsize) {
	size_t file_len = ftell(f);
	const char* encode = fileencodedetect(f);
	fseek(f, 0L, SEEK_END);  
	file_len = ftell(f) - file_len;
	fseek(f, -file_len, SEEK_END);
	char* inbuf = (char*) malloc (file_len);
	fread(inbuf, 1, file_len, f);
	echar_t* outbuf = code2echar(inbuf, outsize, encode);
	FreeStr(inbuf);
	return outbuf;
}

extern echar_t*
autoreadchar (const char* data, size_t* outsize) {
	const char* encode = encodedetect(data);
	return code2echar(data, outsize, encode);
}


extern size_t
estrlen (const echar_t* str) {
	assert (str != NULL);
	const echar_t* p; size_t size = 0;
	for (p = str; *p != 0; ++p) {
		++size;
	}
	return size;
}

extern void
free_str(void** p) {
	if (*p != NULL) {
		free(*p);
		*p = NULL;
	}
}
