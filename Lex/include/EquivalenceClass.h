
#ifndef EQUIVALENCE_CLASS_H
#define EQUIVALENCE_CLASS_H

#include "CharSet.h"
#include <vector>
#include <set>
using namespace std;

/*
 * 等价类
 * 这里为了解析Unicode编码，采用了等价类压缩的思想
 * 将所有的可能的值编码为1-n，作为n个等价类
 * 0为所有非法字符
 * 这样可以大大减小空间占用
 */
class EquivalenceClass
{
public:
	EquivalenceClass();
	~EquivalenceClass();

	void Add(CharSet &charset);
	void Init();

	set<unsigned short> makeSet(CharSet &charset);

	unsigned short getClass(gunichar);

	int getSum();

	void print();
private:
	void insert(gunichar p, gunichar q, int xs);

	int eclass_sum = 0;
	vector<unsigned short> equivalence_class;
};


#endif // EQUIVALENCE_CLASS_H
