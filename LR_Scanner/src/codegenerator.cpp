#include "codegenerator.h"

const int intsize = sizeof(int);

CodeGenerator::CodeGenerator()
{
}

int CodeGenerator::getPointer() {
    return data.size();
}

void CodeGenerator::WriteInt(int d) {
    int* p = &d;
    char* c = (char*)p;
    for (int i = 0; i < intsize; ++i) {
        data.push_back(*c);
        ++c;
    }
}

void CodeGenerator::Write(int p,int l, int a) {
    printf("write: %d\t%d\t%d\n",p,l,a);
    data.push_back((char)p);
    WriteInt(l);
    WriteInt(a);
}

void CodeGenerator::Write(int p, int a) {
    printf("write: %d\t%d\n",p,a);
    data.push_back((char)p);
    WriteInt(a);
}

void CodeGenerator::Write(int p) {
    printf("write: %d\n",p);
    data.push_back((char)p);
}

void CodeGenerator::WriteFile(const char* path) {
    outfile.open(path,ios::binary|ios::out);
    if (!outfile.is_open()) {
        printf("output file is not open!\n");
        return;
    }
    outfile.write(data.c_str(),data.size());
    outfile.close();
}

void CodeGenerator::WritePointer(int p, int a) {
    int* pa = &a;
    char* c = (char*)pa;
    for (int i = p; i < p + intsize; ++i) {
        data[i] = *c;
        ++c;
    }
}
