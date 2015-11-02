#include "EquivalenceClass.h"


EquivalenceClass::EquivalenceClass()
{
	equivalence_class.resize(65536);
}


EquivalenceClass::~EquivalenceClass()
{

}

void EquivalenceClass::Add(CharSet &cset)
{
	auto charset = cset.charset;
	eclass_sum++;
	wchar_t t;
	for (auto i = charset.begin(); i != charset.end(); ++i)
	{
		if (i->second.type == 0) {
			insert(i->first, i->first);
		}
		if (i->second.type == 1) {
			t = i->first;
			++i;
			i->first;
			insert(t, i->first);
		}
	}

	// 等价类编号压缩
	// 这里采用的方法是，如果有新添加字符集合，就将该集合中的数字直接覆盖当前
	// 等价类表中的数字，并重新编号命名，这样如果所有的数字都被覆盖一遍，最多会
	// 使得当前等价类的个数×2,
	// 所以我们应当再使用另外一个映射数组，将重复的没必要的数据删掉
	// 这样就能实现等价类的添加了
	vector<unsigned short> v(eclass_sum * 2);

	for (auto i = equivalence_class.begin(); i != equivalence_class.end(); ++i)
	{
		v[*i] = *i;
	}
	int p = 0;
	for (int i = 1; i < eclass_sum * 2; ++i)
	{
		if (v[i] != 0) {
			++p;
			v[i] = p;
		}
	}
	eclass_sum = p;
	for (auto i = equivalence_class.begin(); i != equivalence_class.end(); ++i)
	{
		*i = v[*i];
	}
}

void EquivalenceClass::insert(wchar_t p, wchar_t q)
{
	for (wchar_t k = p; k <= q; ++k)
	{
		equivalence_class[k] += eclass_sum;
	}
}

void EquivalenceClass::Init()
{

}

int EquivalenceClass::getSum(){
	return this->eclass_sum;
}

// 这里可以将原来的字符集转换为等价类的表示法，变为等价类集合
set<unsigned short> EquivalenceClass::makeSet(CharSet &charset)
{
	set<unsigned short> class_set; wchar_t t,last;
	for (auto i = charset.charset.begin(); i != charset.charset.end(); ++i)
	{
		if (i->second.type == 0) {
			class_set.insert(equivalence_class[i->first]);
		}
		if (i->second.type == 1) {
			t = i->first;
			++i;
			last = 0;
			for (wchar_t k = t; k <= i->first;++k)
			{
				if (last != equivalence_class[k]) {
					last = equivalence_class[k];
					class_set.insert(last);
				}
			}
		}
	}
	return class_set;
}

unsigned short EquivalenceClass::getClass(wchar_t c)
{
	return equivalence_class[c];
}
