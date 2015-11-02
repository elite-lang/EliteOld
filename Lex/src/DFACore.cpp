#include "DFACore.h"

LexToken* DFACore::Read() {
    state = 0;
    tokendata.clear();
    LexToken* t = new LexToken();
    wchar_t nowdata;
    while ((nowdata = data[point]) != 0) {
        // for each word ,may get it Equal Class
        wchar_t c = pEClass->getClass(nowdata);

        // test the next state
        int nextstate = dfa->nextState(state, c);
        int p = dfa->isStopState(state);
        // if the state is stopped and the next is fault, get the token
        if (p!=-1 && nextstate == -1) {
            if (p == 0) {
                state = 0;
                tokendata.clear();
                continue;
            } else {
                t->type = p;
                t->data = tokendata;
                t->row_num = row_point;
                t->col_num = line_point;
                state = 0;
                tokendata.clear();
                return t;
            }
        }
        if (nextstate==-1) {
            printf("ERROR STATE row: %d line: %d \n",row_point,line_point);
            return t;
        }
        state = nextstate;
        tokendata.push_back(nowdata);


        // make the right row number and line number
        if (nowdata == '\n') {
            ++row_point;
            line_point = 0;
        }
        ++point;
        ++line_point;
    }
    t->type = 0;// 0 is the error type
    return t;
}
