#ifndef MEMBLOCK_HPP
#define MEMBLOCK_HPP

#include <cstdlib>
#include <set>

void* operator new (size_t size, const char* ptr) {
    int* p = (int*) malloc(size + sizeof(int));
    *p = 1;
    return p + 1;
}


template<typename T>
class sptr {
public:
    sptr(T* p) {
        ptr = p;
    }
    sptr<T>& operator=(T* p) {
        ptr = p;
    }

    sptr(const sptr<T>& p) {
        ptr = p.ptr;
        ref();
    }
    sptr<T>& operator=(const sptr<T>& p) {
        ptr = p.ptr;
        ref();
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
        int* r = (int*) ptr - 1;
        (*r)++;
    }
    void unref() {
        int* r = (int*) ptr - 1;
        (*r)--;
        if (*r == 0) {
            ptr->~T();
            free(r);
        }
    }

    T* ptr;
};


#endif /* end of include guard: MEMBLOCK_HPP */
