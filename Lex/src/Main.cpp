/* 
* @Author: sxf
* @Date:   2014-10-02 17:39:24
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 20:16:46
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DFA.h"
#include "EquivalenceClass.h"
#include <Lex.h>

using namespace std;  
  
#define tab "\t"  
  
EquivalenceClass* pEClass;

Lex lex;

void test1();
void printTree(node* p,int n);

char* fileReader(const char* path) {
    fstream file; int flen;
    file.open(path);//打开文件
    if(!file.is_open())
    {
        printf("can not open BNF file!\n");
        return NULL;
    }
    file.seekg(0,ios::end);
    flen = file.tellg();
    file.seekg(0,ios::beg);
    char* data = new char[flen+1];
    file.read(data,flen);
    file.close();
    data[flen] = 0;
    return data;
}

int main()
{    
    lex.ReadConfig("/mnt/data/workspace/Complier/Lex/build/lex.txt");
    char* data = fileReader("/mnt/data/workspace/Complier/Lex/build/test.txt");
    lex.Init(data);
    Token* t = lex.Read();
    while (t->type != 0 && t->type != EOF) {
        printf("%s \t %d \t row:%d \t col:%d\n",t->pToken,t->type,t->row_num,t->col_num);
        t = lex.Read();
    }
    return 0;  
}  

void printTree(node* p,int n) {
	if (p == 0) return;
	for (int i = 0; i < n; ++i)
		printf("    ");
	printf("  |-- ");
	if (p->type != 0)
		printf("%c",p->type);
	else 
		wcout << p->data->str;
	printf("\n");

	printTree(p->left, n + 1);
	printTree(p->right, n + 1);
}

// void test1() {
// 	CharSet* c = new CharSet(L"a-yzA-Z1-90");
// 	auto s = c->charset;
// 	for (auto i = s.begin(); i != s.end(); ++i) {
// 		cout << ((int)(*i).first) << '\t' << ((int)(*i).second.type) << '\t' << ((int)(*i).second.eclass) << endl;
// 	}
	
// 	CharSet q(L"a-z01.");

// 	EquivalenceClass ec;
// 	ec.Add(*c);
// 	ec.Add(q);
// 	auto p1 = ec.makeSet(*c);
// 	auto p2 = ec.makeSet(q);
// 	for (auto p = p1.begin(); p != p1.end(); ++p)
// 	{
// 		cout << *p << ' ';
// 	}
// 	cout << endl;
// 	for (auto p = p2.begin(); p != p2.end(); ++p)
// 	{
// 		cout << *p << ' ';
// 	}
// 	cout << endl;
// 	delete c;

// 	pEClass = new EquivalenceClass();
	
// 	Regex* re = new Regex(L"abc(dd|eb)*k", pEClass);

// 	wcout << L"abc(dd|eb)*k" <<endl;
// 	printTree(re->getRoot(), 0);

// 	DFA* dfa = new DFA();
// 	dfa->setEClass(pEClass);
// 	dfa->Init(re);
// 	dfa->print_func();

// 	delete pEClass;
// 	pEClass = new EquivalenceClass();

// 	Regex* re2 = new Regex(L"(a|b)*abb", pEClass);
// 	wcout << L"(a|b)*abb" << endl;
// 	printTree(re2->getRoot(), 0);

// 	DFA* dfa2 = new DFA();
// 	dfa2->setEClass(pEClass);
// 	dfa2->Init(re2);
// 	dfa2->print_func();
	
// 	/// for homework
// 	delete pEClass;
// 	pEClass = new EquivalenceClass();
// 	Regex* homework1 = new Regex(L"1(0|1)*|0", pEClass);
// 	wcout << L"1(0|1)*|0" << endl;
// 	printTree(homework1->getRoot(), 0);
// 	DFA homework_dfa1;
// 	homework_dfa1.setEClass(pEClass);
// 	homework_dfa1.Init(homework1);
// 	homework_dfa1.print_func();
// 	homework_dfa1.print_StateMap();
	
// 	delete pEClass;
// 	pEClass = new EquivalenceClass();
// 	Regex* homework2 = new Regex(L"1(1010*|1(010)*1)*0", pEClass);
// 	wcout << L"1(1010*|1(010)*1)*0" << endl;
// 	printTree(homework2->getRoot(), 0);
// 	DFA homework_dfa2;
// 	homework_dfa2.setEClass(pEClass);
// 	homework_dfa2.Init(homework2);
// 	homework_dfa2.print_func();
// 	homework_dfa2.print_StateMap();
	
// 	delete pEClass;
// 	pEClass = new EquivalenceClass();
// 	Regex* homework3 = new Regex(L"1(0|1)*101", pEClass);
// 	wcout << L"1(0|1)*101" << endl;
// 	printTree(homework3->getRoot(), 0);
// 	DFA homework_dfa3;
// 	homework_dfa3.setEClass(pEClass);
// 	homework_dfa3.Init(homework3);
// 	homework_dfa3.print_func();
// 	homework_dfa3.print_StateMap();
	
// 	delete pEClass;
// 	pEClass = new EquivalenceClass();
// 	Regex* homework4 = new Regex(L"(0|10)*", pEClass);
// 	wcout << L"(0|10)*" << endl;
// 	printTree(homework4->getRoot(), 0);
// 	DFA homework_dfa4;
// 	homework_dfa4.setEClass(pEClass);
// 	homework_dfa4.Init(homework4);
// 	homework_dfa4.print_func();
// 	homework_dfa4.print_StateMap();
// 	system("pause");
// }
