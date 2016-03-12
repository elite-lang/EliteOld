#ifndef MEMBLOCK_HPP
#define MEMBLOCK_HPP

#include <cstdio>
#include <cstdlib>

void* operator new (size_t size, const char* ptr) {
    int* p = (int*) malloc(size + sizeof(int));
    *p = 1;
    return p + 1;
}


void sptr_ref(void* p) {
    int* k = (int*) p;
    (*k)++;
}

void sptr_unref(void* p) {
    int* k = (int*) p;
    (*k)--;
}


template<typename T>
class sptr {
public:
    sptr(T* p) {
        ptr = p;
    }
    sptr<T>& operator=(T* p) {
        ptr = p;
        return *this;
    }

    sptr(const sptr<T>& p) {
        ptr = p.ptr;
        ref();
    }
    sptr<T>& operator=(const sptr<T>& p) {
        ptr = p.ptr;
        ref();
        return *this;
    }

    ~sptr() {
        unref();
    }

    T* get() {
        return ptr;
    }
    void wrapper(T* p) {
        ptr = p;
    }
    T* unwrapper() {
        ref();
        return ptr;
    }

    T* operator -> () {
        return ptr;
    }
    T& operator * () {
        return *ptr;
    }

protected:
    void ref() {
        printf("ref\n");
        int* r = (int*) ptr - 1;
        (*r)++;
    }
    void unref() {
        printf("unref\n");
        int* r = (int*) ptr - 1;
        (*r)--;
        if (*r == 0) {
            ptr->~T();
            free(r);
            printf("free\n");
        }
    }

    T* ptr;
};


#endif /* end of include guard: MEMBLOCK_HPP */
