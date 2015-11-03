#pragma once

#include "Regex.h"
#include <list>
using namespace std;


// 从0状态开始，0为初始状态
class DFA
{
public:
	DFA();
	~DFA();

	// it will build a DFA from the regex grammer tree
	void Init(Regex* re);

    // build the DFA
    void CreateDFA();

	// it's used for debug
	void print_func();

	// ========== State Map =========
	
	// used to get the next state
	int nextState(int s,wchar_t a);
	// add a new edge fo
	void addEdge(int s, int obj, wchar_t a);
    // is the stop state
    int isStopState(int s);

	// === setter and getter ===

	void setEClass(EquivalenceClass* pEClass);
	EquivalenceClass* getEClass();
	int getStateSum();  // 得到总状态数，从0状态开始，故为最大状态号+1

    void setStopState(int s,int t) {
        stopState.insert(make_pair(s,t));
    }

	// ===== for debug ======
	// 打印DFA状态图
	void print_StateMap();
private:
	// calculate the pos;
	void dfs(node*);
	void cal_first_and_last();
	void cal_follow();


	vector<node*> node_vec;
	vector<node_func*> node_function;

	set<node*> GetNextSet(set<node*> &setNode, CharSet p);
	bool IsNodeSetInList(set<node*> &setNodeNext, int &nIdx);
	bool IsContainAcceptingState(set<node*> &setNode);
	bool Check(const wchar_t* data);
	vector<set<node*>> listSet;
	
	EquivalenceClass* pEClass;
	
    Regex* re;

    map<int,int> stopState;
public:
	int Top;
	
	vector<wchar_t>	m_default;
	vector<int>	m_base;
	vector<wchar_t>	m_next;
	vector<int>	m_check;

// 	int state_base; // 表示状态初始状态的开始标号 已弃用
// 	void setState_base(int _b) { state_base = _b; }
// 	int getState_base() { return state_base; }
	
};

