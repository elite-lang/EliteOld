#include <string>
#include <fstream>
using namespace std;

#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

class CodeGenerator
{
public:
    CodeGenerator();

    int getPointer();
    void Write(int p);
    void Write(int p, int a);
    void Write(int p,int l, int a);
    void WriteFile(const char* path);
    void WritePointer(int p, int a);

private:
    string data;
    fstream outfile;

    void WriteInt(int d);
};

#endif // CODEGENERATOR_H
