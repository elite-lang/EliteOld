#include "CharSet.h"
#include <vector>
using namespace std;


CharSet::CharSet()
{
}


CharSet::~CharSet()
{
}


CharSet::CharSet(const CharSet& copy) {
	eclass_sum = copy.eclass_sum;
	charset.insert(copy.charset.begin(),copy.charset.end());
}

CharSet::CharSet(const Glib::ustring _str) {
    this->str = _str;
	gunichar last = 0;
	this->eclass_sum = 1;
	bool isConnector = false;
	for (auto i = str.begin(); i != str.end(); ++i)
	{
		if (i == str.begin() && (*i == '^')) {
			negate = true;
		}
		else {
			if (*i == '-') {
				if (last == 0 || isConnector){
					// throw exception("error, \'-\' is not right");
				}
				
				isConnector = true;
			}
			else {
				gunichar c = *i;
				if (c == '\\') {
					c = CharEscape(i);
				}
		
				if (isConnector) {
					insert(last,c); 
					last = 0;
					isConnector = false;
				}
				else {
					if (last != 0) {
						insert(last);
						last = 0;
					}
					last = c;
				}
			}
		}
	}
	if (last != 0) {
		insert(last);
	}
}

// void CharSet::Combine(const CharSet& obj) {
// 	eclass_sum++;
// 	gunichar t;
// 	for (auto i = obj.charset.begin(); i != obj.charset.end(); ++i)
// 	{
// 		if (i->second.type == 0)
// 			insert(i->first, i->first, 0);
// 		if (i->second.type == 1) {
// 			t = i->first;
// 			++i;
// 			insert(t, i->first, 0);
// 		}
// 	}
	
// 	// 等价类编号压缩
// 	vector<unsigned short> v(eclass_sum * 2);
	
// 	for (auto i = charset.begin(); i != charset.end(); ++i)
// 	{
// 		v[i->second.eclass] = i->second.eclass;
// 	}
// 	int p = 0;
// 	for (int i = 1; i < eclass_sum * 2; ++i)
// 	{
// 		if (v[i] != 0) {
// 			++p;
// 			v[i] = p;
// 		}
// 	}
// 	for (auto i = charset.begin(); i != charset.end(); ++i)
// 	{
// 		i->second.eclass = v[i->second.eclass];
// 	}
// }

// void CharSet::insert(gunichar p, gunichar q, unsigned short eclass) {
// 	if (p != q) {
		

// 	}
// 	else {
// 		// 单个元素的插入

// 	}
// }


void CharSet::insert(gunichar p, gunichar q) {
	if (p == q) {
		insert(p);
		return;
	}
	//charset.insert(make_pair(p, cv(1,1)));
	//charset.insert(make_pair(q, cv(-1, 1)));
	charset[p].type = 1;
	charset[q].type = -1;
	map<gunichar, cv>::iterator f, l;
	auto i = charset.find(p);
	if (i == charset.begin() || ( (i->first - (--i)->first > 1) && (i->second.type != 1)))
	{
		// 自身不删，从自己后面删除
		if (i->first == p)
			f = ++i;
		else
			f = ++++i; // - -!
	}
	else {
		if (i->second.type == 1) {
			// 自身前面的不删，从自身开始删
			f = ++i;
		}
		else {
			// 从自身前面的开始删
			f = i;
		}
	}

	auto j = charset.find(q);
	if ((++j) == charset.end() || (j->first - (--j)->first > 1) && ((++j)->second.type != -1))
	{
		// 自身不删，前面开始删
		l = charset.find(q);
	}
	else {
		if (j->second.type == -1) {
			// 自身后面的不删，从自身开始往前删
			l = j;
		}
		else {
			// 自身后面的也要删
			l = ++j;
		}
	}
	if (l->first > f->first)
		charset.erase(l, f);
}

void CharSet::insert(gunichar c) {
	auto i = charset.find(c);
	if (i == charset.end()) {
		charset[c].type = 0;
		i = charset.find(c);
		auto j = i;
		// 前面有左括号
		if (j != charset.begin() && ((--j)->second.type == 1))
		{
			charset.erase(i);
			return;
		}
		j = i;
		if (j != charset.begin() && ((--j)->second.type == -1) && (i->first - j->first == 1))
		{
			charset.erase(j);
			i->second.type = -1;
			return;
		}
		j = i;
		if ((++j) != charset.end() && (j->second.type == 1) && (j->first - i->first == 1))
		{
			charset.erase(j);
			i->second.type = 1;
			return;
		}
	}
}

bool operator==(const cv& q, const cv& p)
{
	return ((q.type == p.type) && (q.eclass == p.eclass));
}

bool CharSet::operator==(const CharSet& p)
{
	return (this->charset == p.charset);
	//return false;
}

// 转义函数，注意将指针指到转义的结尾就行，不用加1
gunichar CharSet::CharEscape(Glib::ustring::iterator& i) {
	++i; int ws;
	switch (*i)
	{
		// 空白字符集合
		case 'n': return '\n';
		case 't': return '\t';
		case 'r': return '\r';
		case 'f': return '\f';
		case 'v': return '\v';

		// 16进制表示数
		case 'u':  // 后接4位的16进制数字
			ws = 4;	goto EscapeChange;	
		case 'x': { // 后接2位16进制数
			ws = 2; goto EscapeChange;	
		}
		default: return *i;
	}
EscapeChange:
	Glib::ustring num;
	for (int j = 0; j< ws; ++j) {
		++i; num += *i;
	}
	gunichar c = (gunichar) HexToDec(num.c_str());
	return c;
}

//返回16进制字符串s对应的整数值，遇到任何一个非法字符都返回-1。
int CharSet::HexToDec(const char *s)
{
    const char *p = s;

    //空串返回0。
    if(*p == '\0')
        return 0;

    //忽略开头的'0'字符
    while(*p == '0')
        p++;

    int dec = 0;
    char c;

    //循环直到字符串结束。
    while(c = *p++)
    {
        //dec乘16
        dec <<= 4;

        //数字字符。
        if(c >= '0' && c <= '9')
        {
            dec += c - '0';
            continue;
        }

        //小写abcdef。
        if(c >= 'a' && c <= 'f')
        {
            dec += c - 'a' + 10;
            continue;
        }

        //大写ABCDEF。
        if(c >= 'A' && c <= 'F')
        {
            dec += c - 'A' + 10;
            continue;
        }

        //没有从任何一个if语句中结束，说明遇到了非法字符。
        return -1;
    }

    //正常结束循环，返回10进制整数值。
    return dec;
}


//CharSet::CharSet(std::wstring str) {
//	this->str = std::wstring(str);
//	gunichar last = 0;
//	this->eclass_sum = 1;
//	bool isConnector = false;
//	for (auto i = str.begin(); i != str.end(); ++i)
//	{
//		if (i == str.begin() && (*i == '^')) {
//			negate = true;
//		}
//		else {
//			if (*i == '-') {
//				if (last == 0 || isConnector){
//					throw new std::exception("error, '-' is not right", 1001);
//				}
//				insert(last, 1);
//				last = 0;
//				isConnector = true;
//			}
//			else {
//				gunichar c = *i;
//				if (*i == '\\') {
//
//				}
//
//				if (isConnector) {
//					insert(c, -1);
//					isConnector = false;
//				}
//				else {
//					if (last != 0) {
//						insert(last, 0);
//						last = 0;
//					}
//					last = c;
//				}
//			}
//		}
//	}
//	if (last != 0) {
//		insert(last, 0);
//	}
//}
//
//void CharSet::Combine(CharSet& obj) {
//	eclass_sum++;
//	for (auto i = obj.charset.begin(); i != obj.charset.end(); ++i)
//	{
//		insert((*i).first, i->second.type, 0);
//	}
//
//	// 等价类编号压缩
//	vector<unsigned short> v(eclass_sum * 2);
//
//	for (auto i = charset.begin(); i != charset.end(); ++i)
//	{
//		v[i->second.eclass] = i->second.eclass;
//	}
//	int p = 0;
//	for (int i = 1; i < eclass_sum * 2; ++i)
//	{
//		if (v[i] != 0) {
//			++p;
//			v[i] = p;
//		}
//	}
//	for (auto i = charset.begin(); i != charset.end(); ++i)
//	{
//		i->second.eclass = v[i->second.eclass];
//	}
//}
//
//// 抽象出来，将任意一个符号插入时的分割操作
//void CharSet::insert(gunichar c, char type, unsigned short eclass) {
//	//charset[c] = type;
//	auto p = charset.find(c);
//	if (p != charset.end()) {
//		char old_type = p->second.type;
//		if (old_type != 0) { //避免出现死递归
//			p->second.type = 0;
//			p->second.eclass += eclass_sum;
//			// 这段代码实际上是精简了两种情况，+1 是向右移动，-1是向左移动
//			insert(c + old_type, old_type, p->second.eclass);
//		}if (type != old_type) {
//			if (type != 0) { // 另外的情况
//				// 在原来类型0上插入1或-1的情况
//				p->second.eclass += eclass_sum;
//				insert(c + type, type, p->second.eclass);
//			}
//		}
//	}
//	else {
//		cv v;
//		v.type = type;
//		v.eclass = eclass_sum;
//		p = charset.find(c);
//		if (p != charset.begin()){
//			--p;
//			if (p->second.type == 1) {
//				if (type == 0) { // 两括弧中嵌入一个单个元素
//					v.eclass = eclass_sum + p->second.eclass;
//					insert(c - 1, -1, p->second.eclass);
//					insert(c + 1, 1, p->second.eclass);
//				}
//				else {
//					(++p);
//					if ((++p) != charset.end() && (p->second.type == -1)){
//						v.eclass = eclass_sum + p->second.eclass;
//						insert(c - type, -type, p->second.eclass);
//					}
//				}
//			}
//		}
//		if (eclass != 0) v.eclass = eclass;
//		charset[c] = v;
//	}
//}


//void CharSet::insert(gunichar c, char type) {
//	//charset[c] = type;
//	auto p = charset.find(c);
//	if (p != charset.end()) {
//		char old_type = p->second.type;
//		if (old_type != 0) { //避免出现死递归
//			p->second.type = 0;
//			// 这段代码实际上是精简了两种情况，+1 是向右移动，-1是向左移动
//			insert(c + old_type, old_type);
//		}if (type != old_type) {
//			if (type != 0) { // 另外的情况
//				insert(c + type, type);
//			}
//		}
//	}
//	else {
//		charset[c].type = type;
//		charset[c].eclass = 1;
//		p = charset.find(c);
//		if (p != charset.begin()){
//			if ((--p)->second.type == 1) {
//				if (type == 0) {
//					insert(c - 1, -1);
//					insert(c + 1, 1);
//				}
//				else {
//					(++p);
//					if ((++p) != charset.end() && (p->second.type == -1)){
//						insert(c - type, -type);
//					}
//				}
//			}
//		}
//	}
//}
