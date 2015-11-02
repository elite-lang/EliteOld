#include "State.h"
#include <cstddef>


State::State()
{
    init();
}

State::State(const State& other)
{
    init();
}

void State::init(){
    children = NULL; //此指针列表里放入state的定义项
    brother  = NULL;
    script = NULL;
    state_const = NULL;
    state_class = NULL;
    state_var = NULL;
    Repeatable = 0;
    isList = true;
}

State::~State()
{
    delete[] state_const;
    delete[] state_const;
    delete[] state_var;
    if (children != NULL) delete children;
    if (brother != NULL) delete brother;
}

State& State::operator=(const State& other)
{

}

bool State::operator==(const State& other)
{
    // TODO: 十分重要，需要增加不同情况的判断两个State是否相等的方法
    return (this->id == other.id);
}

void State::AddBrotherState(State* _brother)
{
    if (_brother == this) return;
    State* p = this;
    State* q = p->brother;
    while (q != NULL) { p = q; q = p->brother; }
    if (_brother == p) return;
    p->brother = _brother;
}

void State::AddChildrenState(State* _children)
{
    if (children == NULL) 
	children = _children;
    else
	children->AddBrotherState(_children);
}


