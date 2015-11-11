/* 
* @Author: sxf
* @Date:   2015-01-02 16:28:17
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-10 19:51:47
*/

#ifndef GRAMMER_NODE_H
#define GRAMMER_NODE_H

#include <iostream>


#define remove_ptr(P) if (P != 0) { delete P; P = 0; }

class Grammer_Node {
public:
    Grammer_Node* children;
    Grammer_Node* brother;
    int grammer_id; // 唯一的语法翻译标识符
    int token_type; // 词法元素的类型
    void* token_data; // 词法元素的值，根据类型进行强制转换
    int lua_data; // lua中节点属性表的引用

    Grammer_Node(){
        children = NULL;
        brother  = NULL;
    }
    Grammer_Node(const Grammer_Node& _node){
    	children = _node.children; brother = _node.brother; grammer_id = _node.grammer_id;
    	token_type = _node.token_type; token_data = _node.token_data;
    }
    Grammer_Node(Grammer_Node* _children, Grammer_Node* _borther){
	   children = _children; brother  = _borther;
    }
    ~Grammer_Node(){
    	remove_ptr(children);
    	remove_ptr(brother);
    }
    virtual Grammer_Node* AddBortherNode(Grammer_Node* _brother);
    virtual Grammer_Node* AddChildrenNode(Grammer_Node* _children);
    static Grammer_Node* NewNode();
};

#endif // GRAMMER_NODE_H


