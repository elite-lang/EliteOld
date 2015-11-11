/* 
* @Author: sxf
* @Date:   2015-01-01 23:48:42
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-11 21:00:58
*/

#ifndef LEX_INTERFACE_H
#define LEX_INTERFACE_H

//it's a token for return
struct Token
{
	const char* pToken;
	int type;
    int col_num;
	int row_num;
};

class LexInterface 
{
public:
    // 初始化词法分析器，如果不传入值，则是希望通过setData接口传入
    virtual void Init(const char* pData = 0) = 0;

	// 从输入流读取下一个字符， 无需释放资源，再下一次Read时，自动释放上个资源
    virtual Token* Read() = 0;

    // 对应每个规则，询问其名称是什么，为了在语法定义中和对应的id关联
    virtual const char* getRule(int id) = 0;
    
    // 获取总共有多少个词法规则
    virtual int getRuleSize() = 0;

    // 设置当前分析器解析的数据流
    virtual void setData(const char* pData) = 0;
};

#endif // LEX_INTERFACE_H

