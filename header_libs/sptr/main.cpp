#include "sptr.hpp"

int main() {
    sptr<int> p = new ("") int;
    *p = 15;
    {
        sptr<int> g = p;
        printf("%d\n", *g);
    }
    int* k = p.unwrapper();
    printf("%d\n", *k);
    sptr<int> v = k; // 这里必须保证一个指针仅仅传给一个sptr
    printf("%d\n", *v);

    return 0;
}
