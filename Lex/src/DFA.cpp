#include "DFA.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
DFA::DFA()
{
    re = NULL;
}


DFA::~DFA()
{

}

void DFA::Init(Regex* _re)
{
    this->re = _re;

}

bool DFA::Check(const wchar_t* data)
{
	int statue = 0;
	for (int p = 0; data[p] != 0; ++p) {
		statue = nextState(statue, data[p]);
		// 出错
		if (statue == -1) {
			return true;
		}
		// 接受
		if (statue == -2) {
			return false;
		}

	}
}


void DFA::dfs(node* p)
{
	if (p->left != NULL) 
		dfs(p->left);
	if (p->right != NULL)
		dfs(p->right);
	node_func* func = new node_func();
	if (p->type == '?' || p->type == '*')
		func->nullable = true;
	else if (p->type == 1) {
		func->nullable = p->left->func->nullable && p->right->func->nullable;
	} else if (p->type == '|') {
		func->nullable = p->left->func->nullable || p->right->func->nullable;
	}
	else {
		func->nullable = false;
		if (p->data!=NULL)
			p->class_set = pEClass->makeSet(*(p->data));
	}
	func->num = node_vec.size();
	node_vec.push_back(p);
	node_function.push_back(func);
	p->func = func;
}

void DFA::cal_first_and_last()
{
	for (auto i = node_vec.begin(); i != node_vec.end(); ++i)
	{
		auto p = *i;
		if (p->type == '?' || p->type == '*' || p->type == '+'){
			p->func->firstpos = p->left->func->firstpos;
			p->func->lastpos = p->left->func->lastpos;
		} else if (p->type == 1) {
			if (p->left->func->nullable) {
				auto &set1 = p->left->func->firstpos;
				auto &set2 = p->right->func->firstpos;
				auto &result1 = p->func->firstpos;
				set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result1, result1.begin()));
			} else {
				p->func->firstpos = p->left->func->firstpos;
			}

			if (p->right->func->nullable) {
				auto &set1 = p->left->func->lastpos;
				auto &set2 = p->right->func->lastpos;
				auto &result2 = p->func->lastpos;
				set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result2, result2.begin()));
			}
			else {
				p->func->lastpos = p->right->func->lastpos;
			}
		}
		else if (p->type == '|') {
			auto &set1 = p->left->func->firstpos;
			auto &set2 = p->right->func->firstpos;
			auto &result1 = p->func->firstpos;
			set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result1, result1.begin()));

			auto &set3 = p->left->func->lastpos;
			auto &set4 = p->right->func->lastpos;
			auto &result2 = p->func->lastpos;
			set_union(set3.begin(), set3.end(), set4.begin(), set4.end(), inserter(result2, result2.begin()));
		}
		else {
			p->func->firstpos.insert(p);
			p->func->lastpos.insert(p);
		}
	}
}


void DFA::cal_follow(){
	for (auto i = node_vec.begin(); i != node_vec.end(); ++i)
	{
		auto p = *i;
		if (p->type == 1) {
			auto &last = p->left->func->lastpos;
			auto &first = p->right->func->firstpos;
			for (auto k = last.begin(); k != last.end(); ++k)
			{
				auto q = *k;
				q->func->followpos.insert(first.begin(),first.end());
			}
		}
		else if (p->type == '*' || p->type == '+') {
			auto &last = p->left->func->lastpos;
			auto &first = p->left->func->firstpos;
			for (auto k = last.begin(); k != last.end(); ++k)
			{
				auto q = *k;
				q->func->followpos.insert(first.begin(), first.end());
			}
		}
	}
}


void DFA::CreateDFA() {
    // dfs the map
    dfs(re->getRoot());
    // make the four functions
    cal_first_and_last();
    cal_follow();

	// 初始化，将根节点放入队列中
	auto root = (*node_vec.rbegin());
    auto end = (*(++node_vec.rbegin()));
	listSet.push_back(root->func->firstpos);

	// 从头开始遍历队列Q，对其中的每一个集合S考察每一个输入字符（例如a）
	// 可匹配的节点p，所有p的followpos集合再求并集U
	Top = 0;
	int p = 0;
	while (p < listSet.size()) {
		// 计算当前节点的状态标号
		bool b = true;
		m_base.push_back(0);
		m_default.push_back(0);
		// 遍历所有等价类
		int esize = pEClass->getSum();
		for (unsigned short a = 1; a <= esize; ++a)
		{
			std::set<node*> nextset;
			// 查看当前等价类的信息都在哪个集合中出现过
			for (auto i = listSet[p].begin(); i != listSet[p].end(); ++i)
			{
				auto f = (*i)->class_set;
				if (f.find(a) != f.end()) {
					auto g = (*i)->func->followpos;
					nextset.insert(g.begin(),g.end());
				}
			}
			if (nextset.size() != 0) {
				// 第一次找到转移时对base数组进行计算赋值
				if (b) {
					b = false;
					m_base[p] =Top - a;
				}
				// 判断当前节点是否在队列中
				auto i = find(listSet.begin(), listSet.end(), nextset);
				if (i == listSet.end())
				{
					listSet.push_back(nextset);
                    // if the nextset has a stop state, add it to the map
                    if (nextset.find(end)!=nextset.end())
                        setStopState(listSet.size()-1,0);
					i = (--listSet.end());
				}
				// 添加一条转移
				addEdge(p, i - listSet.begin(), a);
			}
		}

		
		///////////
		// 单独判断END

		// 查看当前等价类的信息都在哪个集合中出现过
		for (auto i = listSet[p].begin(); i != listSet[p].end(); ++i)
		{
			auto f = (*i)->type;
			if (f == 2) {
				//auto g = (*i)->func->followpos;
				m_default[p] = 1;
				break;
			}
		}

		///////////
		++p;
	}
	
}



set<node*> DFA::GetNextSet(set<node*> &setNode,CharSet p) {
	set<node*> setNodeNext;
	for (auto i = setNode.begin(); i != setNode.end(); ++i) {
		if (*((*i)->data) == p) {
			
		}
		auto &followpos = (*i)->func->followpos;
		setNodeNext.insert(followpos.begin(),followpos.end());
	}
	return setNodeNext;
}

bool DFA::IsNodeSetInList(set<node*> &setNodeNext, int &nIdx)
{
	auto it = listSet.begin();
	for (nIdx = 0; it != listSet.end(); it++, nIdx++)
	{
		if (*it == setNodeNext)
		{
			return true;
		}
	}
	return false;
}

bool DFA::IsContainAcceptingState(set<node*> &setNode)
{
	for (set<node*>::iterator it = setNode.begin(); it != setNode.end(); it++)
	{
		if (2 == (*it)->type)
		{
			return true;
		}
	}
	return false;
}


void DFA::print_func(){
	printf("\t nullable \t firstpos \t lastpos \t followpos\n");
	for (auto i = node_vec.begin(); i != node_vec.end(); ++i){
		auto p = *i;
		if (p->type == 1)
			wcout << '+' << i - node_vec.begin() << '\t';
		else if (p->type == 2)
			wcout << L"END" << i - node_vec.begin() << '\t';
		else if (p->type != 0)
			wcout << (wchar_t)p->type << i - node_vec.begin() << '\t';
		else {
			wcout << p->data->str;
			wcout << i - node_vec.begin() << '\t';
		}

		if (p->func->nullable) printf("true\t\t"); 
		else printf("false\t\t");
		printf("{");
		bool ppq = false;
		for (auto k = p->func->firstpos.begin(); k != p->func->firstpos.end(); ++k){
			auto c = *k;
			if (!ppq) {
				printf("%d", c->func->num);
				ppq = true;
			}
			else {
				printf(",%d", c->func->num);
			}
		}
		printf("}\t");
		bool kkk = false;
		for (auto kk = p->func->firstpos.begin(); kk != p->func->firstpos.end(); ++kk) {
			if ((*kk)->func->num > 9) kkk = true;
		}
		if (!(p->func->firstpos.size() >= 3 && (kkk))) printf("\t");
		printf("{");
		bool ppp = false;
		for (auto k = p->func->lastpos.begin(); k != p->func->lastpos.end(); ++k){
			auto c = *k;
			if (!ppp) {
				printf("%d", c->func->num);
				ppp = true;
			} else {
				printf(",%d", c->func->num);
			}
		}
		printf("}\t");
		for (auto kk = p->func->lastpos.begin(); kk != p->func->lastpos.end(); ++kk) {
			if ((*kk)->func->num > 9) kkk = true;
		}
		if (!(p->func->lastpos.size()>=3 &&(kkk)) ) printf("\t");
		printf("{");
		bool pp = false;
		for (auto k = p->func->followpos.begin(); k != p->func->followpos.end(); ++k){
			auto c = *k;
			if (!pp) {
				printf("%d", c->func->num);
				pp = true;
			}
			else {
				printf(",%d", c->func->num);
			}
		}
		printf("}\n");
	}

	printf("EClass\n");
	int esize = pEClass->getSum();
	printf("%d\n", esize);

	printf("list\n");
	for (auto i = listSet.begin(); i != listSet.end(); ++i){
		for (auto j = (*i).begin(); j != (*i).end(); ++j) {
			printf("%d ", (*j)->func->num);
		}
		printf("\n");
	}


	printf("base\n");
	for (auto i = m_base.begin(); i != m_base.end(); ++i) {
		printf("%d\t%d\t%d\n", i - m_base.begin(), *i, m_default[i - m_base.begin()]);
	}
	printf("next\n");
	for (auto i = m_next.begin(); i != m_next.end(); ++i) {
		printf("%d\t", *i);
		printf("%d\n", m_check[i - m_next.begin()]);
	}
}

int DFA::nextState(int s, wchar_t a)
{
	if (s == -1) return -1;
    if ((m_base[s] + a >= 0) && (m_base[s] + a < Top) && (m_check[m_base[s] + a] == s))
		return m_next[m_base[s] + a];
	else
	{
		return -1;
	}
}

void DFA::addEdge(int s, int obj, wchar_t a)
{
	int t = m_base[s] + a;
	Top = t + 1;
	if (t >= m_next.size()) m_next.resize(t + 1, -1);
	m_next[t] = obj;
	if (t >= m_check.size()) m_check.resize(t + 1);
	m_check[t] = s;
}

void DFA::setEClass(EquivalenceClass* pEClass)
{
	this->pEClass = pEClass;
}

int DFA::getStateSum(){
    return m_base.size();
}

void DFA::print_StateMap(){

    if (re != NULL)
        printf("=== %s ===\n",re->getPattern());
    else
        printf("==== Main DFA ====\n");
    for (int i = 1; i<= pEClass->getSum(); ++i) {
	printf("\t%d",i);
    }
    printf("\n");
    for (int i = 0; i< getStateSum(); ++i) {
        printf("s%d",i);
        int l;
        if ((l = isStopState(i)) != -1) printf("#%d",l);
        for (int j = 1; j<=pEClass->getSum(); ++j) {
            printf("\ts%d",nextState(i,j));
        }
        printf("\n");
    }
}

EquivalenceClass* DFA::getEClass()
{
	return this->pEClass;
}


int DFA::isStopState(int s) {
    auto p = stopState.find(s);
    if (p != stopState.end()) return p->second;
    return -1;
}
