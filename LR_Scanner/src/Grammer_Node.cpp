#include "Grammer_Node.h"

Grammer_Node* Grammer_Node::AddBortherNode(Grammer_Node* _brother){
    Grammer_Node* p = this;
    Grammer_Node* q = p->brother;
    while (q != NULL) { p = q; q = p->brother; }
    	p->brother = _brother;
}

Grammer_Node* Grammer_Node::AddChildrenNode(Grammer_Node* _children){
    if (children == NULL) 
	children = _children;
    else
	children->AddBortherNode(_children);
}

Grammer_Node* Grammer_Node::NewNode()
{
	return new Grammer_Node();
}