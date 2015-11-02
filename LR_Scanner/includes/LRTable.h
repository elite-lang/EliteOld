/* 
* @Author: sxf
* @Date:   2015-01-03 18:43:13
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 18:43:46
*/

#ifndef LRTABLE_H
#define LRTABLE_H

#include "ItemCollection.h"
#include <vector>
using namespace std;

class LRTable
{
public:
    // 构建LR语法分析表
    virtual void BuildTable(vector<ItemCollection*>) = 0;
    // 查询当前状态的动作
    virtual char ACTION(int, int) = 0;
    // 查询
    virtual int GOTO(int, int) = 0;

    // 测试方法，打印表格
    virtual void printTable() = 0;
};

#endif // LRTABLE_H
