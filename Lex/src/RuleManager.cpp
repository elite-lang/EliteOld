
#include "RuleManager.h"
#include <algorithm>
#include <exception>
#include <queue>
#include <cstring>

RuleManager::RuleManager() {
    pEClass = new EquivalenceClass();
}

RuleManager::~RuleManager() {

}

int RuleManager::AddRule(const char* pName,const char* pPattern)
{
    Glib::ustring name(pName);
    Glib::ustring pattern(pPattern);

    int id = FindRule(pName);
    if (id != -1) { // 已经找到了已有的Rule，更新其
	Rule& r = ruleList[id];
	delete r.dfa;
	r.dfa = new DFA();
    r.name = name;
    r.pattern = pattern;
	r.dfa->setEClass(pEClass);
    Regex* re = new Regex(r.pattern.c_str(), pEClass);
	r.dfa->Init(re);
	return id;
    } 
    // 新建Rule，构建DFA
    Rule r;
    r.dfa = new DFA();
    r.name = name;
    r.pattern = pattern;
    r.dfa->setEClass(pEClass);
    Regex* re = new Regex(r.pattern.c_str(), pEClass);
    r.dfa->Init(re);

    if (name == Glib::ustring("ignore"))
        ruleList.insert(ruleList.begin(),r);
    else
        ruleList.push_back(r);
    return ruleList.size();
}

int RuleManager::FindRule(const char* pName){
    std::string name(pName);
    auto result = std::find(ruleList.begin(), ruleList.end(), name);
    if (result == ruleList.end()) return -1;
    return (int)(result - ruleList.begin());
}

void printvec(vector<int> v) {
    for (auto p = v.begin(); p != v.end(); ++p) {
        printf("\t%d",*p);
    }
    printf("\n");
}

DFA* RuleManager::combineAllDFA(){
    vector<int> states;
    vector<vector<int>> statelist;
    mainDFA = new DFA();
    
    for (auto p = ruleList.begin(); p != ruleList.end(); ++p) {
        states.push_back(0);
        Rule& r = *p;
        r.dfa->CreateDFA();
        r.dfa->print_func();
        r.dfa->print_StateMap();
    }
    statelist.push_back(states);
    addStopState(states,0);
    // printvec(states);
    mainDFA->Top = 0;
    int i = 0;
    while (i<statelist.size())
    {
    	bool b = true;
    	mainDFA->m_base.push_back(0);
    	mainDFA->m_default.push_back(0);
    	// 等价类是从1-n的
    	for (int c = 1; c <= pEClass->getSum(); ++c)
    	{
    	    vector<int>* newvec = new vector<int>();
    	    for (int j = 0; j< ruleList.size(); ++j)
    	    {
    		DFA* dfa = ruleList[j].dfa;
    		int nowstate = statelist[i][j];
    		int nextstate = -1;
    		if (nowstate != -1)
    		    nextstate = dfa->nextState(nowstate,c);
    		newvec->push_back(nextstate);
    	    }
    	    // 第一次找到转移时对base数组进行计算赋值
    	    if (b) {
                b = false;
                mainDFA->m_base[i] = mainDFA->Top - c;
    	    }

    	    int p = testin(*newvec,statelist);
            if (p == -2) {
                statelist.push_back(*newvec);
                p = statelist.size()-1;
                addStopState(*newvec,p);
                // printvec(*newvec);
    	    }
            mainDFA->addEdge(i,p,c);
    	}
    	++i;
    }
    mainDFA->setEClass(this->pEClass);
    mainDFA->print_StateMap();
    // this->pEClass->print();
}

void RuleManager::addStopState(vector<int>& newvec,int p)
{
    for (int i = 0; i < newvec.size(); ++i) {
        DFA* dfa = ruleList[i].dfa;
        if (dfa->isStopState(newvec[i]) != -1) {
            mainDFA->setStopState(p,i);
        }
    }
}

int RuleManager::testin(vector< int > newvec, vector< vector< int > > statelist){
    bool isError = true;
    for (auto p = newvec.begin(); p != newvec.end(); ++p) {
        if (*p != -1) isError = false;
    }
    if (isError) return -1;

    for (auto p = statelist.begin(); p != statelist.end(); ++p)
    {
        if (testequal(newvec, *p)) return p - statelist.begin();
    }
    return -2;
}

bool RuleManager::testequal(vector< int > a, vector< int > b) {
    if (a.size() != b.size()) return false;  // 其实是没必要的，输入保证其相等
    for (int i = 0; i < a.size(); ++i) {
	if (a[i] != b[i]) return false;
    }
    return true;
}

void RuleManager::InitCore(const char* pData) {
    core = new DFACore();
    core->Init(mainDFA,pData,pEClass);
}

Token* RuleManager::Read() {
    return core->Read();
}

// ====setter and getter =============
DFA* RuleManager::getMainDFA(){
    return mainDFA;
}

/*
int RuleManager::AddRule(std::wstring pName, std::wstring pattern){
	int size = ruleList.size();
// 	ruleList.push_back(pName);
	return size;
} 


bool RuleManager::DeleteRule(std::wstring pName){
	auto result = std::find(ruleList.begin(), ruleList.end(), pName);
	if (result == ruleList.end()) return false;
	ruleList.erase(result);
	return true;
}

bool RuleManager::DeleteRule(int id){
	try {
		ruleList.at(id);
	}
	catch (std::exception e) {
		return false;
	}
	ruleList.erase(ruleList.begin()+id);
	return true;
}


bool RuleManager::ChangeRule(std::wstring pName, std::wstring pattern){
    int k = FindRule(pName);
    if (k == -1) return false;
    ruleList[k].pattern = pattern;
    return true;
}

bool RuleManager::ChangeRule(int id, std::wstring pattern){
    try {
	    ruleList.at(id);
    }
    catch (std::exception e) {
	    return false;
    }
    ruleList[id].pattern = pattern;
    return true;
} 



*/
