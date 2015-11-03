#pragma once

#include <map>
#include <string>

typedef struct _cv{
	char type;
	unsigned short eclass;
	_cv() {
		type = 0;
		eclass = 0;
	}
	_cv(char _type,unsigned short _eclass) {
		type = _type;
		eclass = _eclass;
	}
	_cv(const _cv &p) {
		this->type = p.type;
		this->eclass = p.eclass;
	}
} cv;

class CharSet
{
public:
	CharSet();
	~CharSet();

	// copy constructor
	CharSet(const CharSet& copy);

	// make constructor
	CharSet(const std::wstring str);

	void Combine(const CharSet& obj);

	bool operator==(const CharSet&);

	// all the char is saved in the balanced tree.
	std::map<wchar_t, cv> charset; //to make the test,it should be private

	// insert method , type = 0 means a standalone char
	// type = 1 means the begin of a interval, type = 2 means the end of the interval.
	void insert(wchar_t p, wchar_t q, unsigned short eclass);
	void insert(wchar_t p, wchar_t q);
	void insert(wchar_t c);
	std::wstring str;
private:
	// make the set negate
	bool negate = false;

	unsigned short eclass_sum;
};

