#ifndef DFACORE_H
#define DFACORE_H
#include "DFA.h"
#include "Lex.h"
#include "EquivalenceClass.h"
class DFACore
{
public:
    DFACore() {}
    ~DFACore() {}
    DFACore(DFA* _dfa,const wchar_t* _d,EquivalenceClass* _pEClass) { Init(_dfa,_d,_pEClass); }
    void Init(DFA* _dfa,const wchar_t* _d,EquivalenceClass* _pEClass) {
        dfa = _dfa; data = _d; pEClass = _pEClass;
        point = 0; row_point =0; line_point = 0;
    }
    LexToken* Read();

private:
    DFA* dfa;
    int state;
    const wchar_t* data;
    int point, row_point, line_point;

    wstring tokendata;
    EquivalenceClass* pEClass;
};

#endif // DFACORE_H
