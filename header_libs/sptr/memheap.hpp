#ifndef MEM_HEAP_HPP
#define MEM_HEAP_HPP

#include <cstdlib>
#include <unordered_set>
#include <cstdio>
#include <vector>

using namespace std;

class MemHeap {

    // 内部使用的节点类型
    struct MemObjNode {
        size_t size;
        int count;
        void* data[];
    };

public:
    MemHeap() {

    }

    inline static void ref (void* ptr) {
        MemObjNode* p = (MemObjNode*) ((char*) ptr - sizeof(MemObjNode));
        ++(p->count);
    }

    inline static void unref (void* ptr) {
        MemObjNode* p = (MemObjNode*) ((char*) ptr - sizeof(MemObjNode));
        --(p->count);
        if (p->count == 0) getInstance()->release(ptr);
    }

    void* allocate(size_t size) {
        MemObjNode* p = (MemObjNode*) malloc(size + sizeof(MemObjNode));
        if (p == NULL) return NULL;
        p->size = size;
        p->count = 1;
        all.insert(&(p->data));
        printf("allocate %p\n", &(p->data));
        return &(p->data);
    }

    void release(void* ptr) {
        if (ptr == NULL) return;
        MemObjNode* p = (MemObjNode*) ((char*) ptr - sizeof(MemObjNode));
        all.erase(ptr);
        free(p);
        printf("release %p\n", ptr);
    }

    inline static MemHeap* getInstance() {
        static MemHeap instance;
        return &instance;
    }

    inline static void push_stack(void* ptr) {
        getInstance()->stack.insert(ptr);
    }

    inline static void pop_stack(void* ptr) {
        getInstance()->stack.erase(ptr);
    }


    static void runGC() {
        auto inst = getInstance();
        for (void* p : inst->stack) {
            inst->markChildren(p);
        }

        vector<void*> v;
        for (void* ptr : inst->all) {
            MemObjNode* p = (MemObjNode*) ((char*) ptr - sizeof(MemObjNode));
            if (p->count < 0) p->count = -(p->count);
            else v.push_back(ptr);
        }
        for (void* p : v) inst->release(p);
    }

protected:

    unordered_set<void*> stack;
    unordered_set<void*> all;
    void* heap;

    void markChildren(void* ptr) {
        MemObjNode* p = (MemObjNode*) ((char*) ptr - sizeof(MemObjNode));

        // 如果打了标记则退出, 否则设置标记, 标记方式则是改变符号位
        if (p->count < 0) return;
        p->count = -(p->count);
        printf("tag %p\n", ptr);

        size_t size = (p->size) / sizeof(char*);
        char** end = (char**)ptr + size;
        for (char** i = (char**)ptr; i < end; ++i) {
            if (all.find(*i) != all.end()) {
                markChildren(*i);
            }
        }
    }

};



#endif /* end of include guard: MEM_HEAP_HPP */
