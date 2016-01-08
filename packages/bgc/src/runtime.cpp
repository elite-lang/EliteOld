#include <gc/gc.h>
#include <stdio.h>
#include <stdarg.h>
#include <vector>
using namespace std;

extern "C" {
    

extern void* bgc_malloc(int size) {
    printf("bgc_malloc %d\n", size);
    return GC_malloc(size);
}

extern void* bgc_malloc_array(int size, ...) {
    va_list argp;                   /* 定义保存函数参数的结构 */
    va_start( argp, size );
    std::vector<int> wd;
    int v; int num = 1;
    do {
        v = va_arg(argp, int);
        if (v != 0) {
            wd.push_back(v);
            num *= v;
        }
    } while (v != 0);
    va_end( argp );                                   /* 将argp置为NULL */

    int full_size = wd.size()*sizeof(int) + size* num;
    int* ans = (int*) GC_malloc(full_size);
    printf("bgc_malloc_array %d\n", full_size);
    int* i = ans;
    for (auto p = wd.begin(); p != wd.end(); ++p, ++i) {
        *i = *p;
    }
    return (void*) i;
}

}
