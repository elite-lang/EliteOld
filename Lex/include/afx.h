/* 
* @Author: sxf
* @Date:   2014-06-23 23:44:18
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 14:27:54
*/

#ifndef AFX_H
#define AFX_H
#include <string.h>
#include <wchar.h>

#define _UNICODE

#ifndef EOF
#define EOF -1
#endif

#ifndef _UNICODE
#define CHAR char
#define STRLEN(x) strlen(x)
#define STRCPY(x,y) strcpy(x,y)
#define Print printf
#define Strformat sprintf
#define _T(x) x
#define String string

#ifndef Release
#define println(x) printf("%s\n",x);
#else
#define println(x) 
#endif


#else


#define CHAR wchar_t
#define STRLEN(x) wcslen(x)
#define STRCPY(x,y) wcscpy(x,y)
#define Print wprintf
#define Strformat swprintf
#define _T(x) L##x
#define String wstring

#ifndef Release
#define println(x) printf("%S\n",x);
#else
#define println(x) 
#endif

#endif

// typedef char bool;
// #define true 1
// #define false 0

// #define Free(p) if (p!=NULL) free(p)

#endif // AFX_H
