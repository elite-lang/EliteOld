#include "Regex.h"
#include <exception>
#include <iostream>

Regex::Regex()
{
}


Regex::~Regex()
{
	delete root;
}

Regex::Regex(const wchar_t* pattern, EquivalenceClass* pEClass) {
	init(pattern, pEClass);
}

bool Regex::init(const wchar_t* pattern, EquivalenceClass* pEClass) {
	this->pattern = pattern;
	this->setEClass(pEClass);
	pointer = 0;
	try {
		wchar_t c;
		while ((c = pattern[pointer]) != 0) {
			++pointer;
			run(c);
		}
		
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
	while (!operater_stack.empty()) {
		pop();
	}
	operater_stack.push(1);
	obj_stack.push(new node(2, 0, 0, 0));
	pop();

	root = obj_stack.top();
	return true;
}

// 此处使用内联函数避免函数反复调用的开销 - - I don't know what I think...
inline void Regex::run(wchar_t c) {
    if (c == ' ' || c == '\t') return; // jump all space and \t
	if ((!operater_stack.empty()) && (operater_stack.top() == '[') && (c !=']')) {
        tempSet.push_back(c);
		return;
	}
	
	bool tempEnd = true;
	switch(c) {
		case '[':	// *
			operater_stack.push('[');
			tempSet.clear(); 
            return;
		case ']':{	// * end
			operater_stack.pop();
			CharSet* pSet = new CharSet(tempSet);
			doCharSet(pSet);
			break; 
		}
		case '(':	// *
			tempEnd = false;
			if (isEnd)
				push(1);
			push('(');
			break;
		case ')':{	// * end
// 			if (operater_stack.empty()) throw new std::exception("the ) didn't matching", 1003);
			push(')');
			/*wchar_t top;
			while (!operater_stack.empty() && (top = operater_stack.top()) != '('){
				if (top == '|' || top == 1) {
					node* obj = obj_stack.top();
					obj_stack.pop();
					auto obj2 = obj_stack.top();
					obj_stack.top() = new node(top, obj, obj2, 0);
				}
				operater_stack.pop();
			}*/
			break;
		}
		case '{':
			operater_stack.push('{');
			tempLeftInt.clear();
			tempRightInt.clear();
			break;
		case '}':
			if (operater_stack.top() == ',') 
				operater_stack.pop();
			if (operater_stack.top() == '{') 
				operater_stack.pop();
			break;
		case '|':	// *
			/*if (operater_stack.top() != '|') {
				while (!operater_stack.empty() && operater_stack.top() == 1){
					node* obj = obj_stack.top();
					obj_stack.pop();
					node* obj2 = obj_stack.top();
					obj_stack.top() = new node(1, obj, obj2, 0);
					operater_stack.pop();
				}
				operater_stack.push('|');
				push('|');
			}
			else {
				node* obj = obj_stack.top();
				obj_stack.pop();
				node* obj2 = obj_stack.top();
				obj_stack.top() = new node('|', obj, obj2, 0);
			}
			*/
			push('|');
			tempEnd = false;
			break;
		case '*':	// * end
		case '?':	// * end
		case '+':	// * end
            putOperater(c);
			break;
		case '/':
			operater_stack.push('/');
			break;
		case '.':	// 非操作符，但是可以匹配任意值
			operater_stack.push(1);
			break;
		case '\\':{	// *
			CharSet* pSet = makeEscape();
			doCharSet(pSet);
			break; 
		}
		default:{
//			wchar_t str[2];
//			str[0] = c; str[1] = 0;
            CharSet* pSet = new CharSet();
            pSet = new CharSet();
            pSet->insert(c, c);
			doCharSet(pSet);
			break; 
		}
	}
	isEnd = tempEnd;
	
	//处理{3,5}时，通过观察当前符号栈中的栈顶来判断
	// if (operater_stack.top() == '{') {
	// 	if (c == ',') operater_stack.push(',');
	// 	else if (isdigit(c)) {
	// 		tempLeftInt.push_back(c);
	// 	}
	// 	return;
	// }
	// if (operater_stack.top() == ',') {
	// 	tempRightInt.push_back(c);
	// 	return;
	// }

	return;
}


void Regex::doCharSet(CharSet* pSet){
	if (isEnd)
		push(1);
	node* pNode = new node(0, 0, 0, pSet);
	pEClass->Add(*pSet);
	obj_stack.push(pNode);
	/*
	wchar_t ope;
	if (!operater_stack.empty() && ((ope = operater_stack.top()) == 1 )) {
		auto top = obj_stack.top();
		obj_stack.top() = new node(1, top, pNode, 0);
		operater_stack.pop();
	}
	else {
		obj_stack.push(pNode);
	}*/
}


void Regex::push(wchar_t c){
	switch (c){
	case 1:{
		wchar_t ope;
		while (!operater_stack.empty() && ((ope = operater_stack.top()) == 1)) {
			pop();
		}
		operater_stack.push(1);
		break; 
	}
	case '|':{
		wchar_t ope;
		while (!operater_stack.empty() && ((ope = operater_stack.top()) == 1 || ope == '|')) {
			pop();
		}
		operater_stack.push('|');
		break;
	}
	case '(':
		operater_stack.push('(');
		break;
	case ')':{
// 		if (operater_stack.empty()) throw new std::exception("the ) didn't matching", 1003);
		wchar_t top;
		while (!operater_stack.empty() && (top = operater_stack.top()) != '('){
			pop();
		}
		if (top == '(')
		    pop();
		break; 
	}
	default:
		break;
	}
}

void Regex::pop(){
	wchar_t top = operater_stack.top();
	if (top == '|' || top == 1) {
		node* obj = obj_stack.top();
		obj_stack.pop();
		node* obj2 = obj_stack.top();
		obj_stack.top() = new node(top, obj2, obj, 0);
	}
	operater_stack.pop();
}

void Regex::doOperater(wchar_t c){

}

void Regex::operate(){
	wchar_t top = operater_stack.top();
	operater_stack.pop();
	switch (top) 
	{
        case '+':
        case '?':
        case '*':
        {
            node* obj = obj_stack.top();
            node* p = obj;
            obj_stack.top() = new node(top, p, 0, 0);
            break;
        }
        default:
        break;
    };
	
}

void Regex::putOperater(wchar_t c){
// 	if (obj_stack.empty())
// 	    throw new std::exception("empty obj_stack");
	node* obj = obj_stack.top();
	node* p = obj;
	obj_stack.top() = new node(c, p, 0, 0);
}

CharSet* Regex::makeEscape() {
	wchar_t c = this->pattern[pointer];
    ++pointer;
    printf("%C",c);
	CharSet* pSet;
	if (c != 0) {
		switch (c)
		{
			// 常用字符集
			case 'd': // [0-9]
				pSet = new CharSet(L"0-9");
				break;
			case 'D': // [^0-9]
				pSet = new CharSet(L"^0-9");
				break;
			case 'w': // [A-Za-z0-9_]
				pSet = new CharSet(L"A-Za-z0-9_");
				break;
			case 'W': // [^A-Za-z0-9_]
				pSet = new CharSet(L"^A-Za-z0-9_");
				break;
			case 's': // [\f\n\r\t\v]
                pSet = new CharSet(L" \f\n\r\t\v");
				break;
			case 'S': // [^\f\n\r\t\v]
                pSet = new CharSet(L"^ \f\n\r\t\v");
				break;

			// 匹配单词边界(暂不支持) 
			case 'b':
				break;
			case 'B':
				break;

			// 空白字符集合
			case 'n':
				pSet = new CharSet();
                pSet->insert('\n', '\n');
				break;
			case 't':
				pSet = new CharSet();
                pSet->insert('\t', '\t');
				break;
			case 'r':
				pSet = new CharSet();
                pSet->insert('\r', '\r');
				break;
			case 'f':
				pSet = new CharSet();
                pSet->insert('\f', '\f');
				break;
			case 'v':
				pSet = new CharSet();
                pSet->insert('\v', '\v');
				break;

			// 16进制表示数
			case 'u': // 后接4位的16进制数字
				break;
			case 'x': // 后接2位16进制数
				break;
			default:{
//				wchar_t str[2];
//				str[0] = c; str[1] = 0;
//				pSet = new CharSet(str);
                pSet = new CharSet();
                pSet->insert(c, c);
				break;
			}
		}
		
	}
    return pSet;
}

inline void Regex::setEClass(EquivalenceClass* pEClass)
{
	this->pEClass = pEClass;
}

inline EquivalenceClass* Regex::getEClass()
{
	return this->pEClass;
}
