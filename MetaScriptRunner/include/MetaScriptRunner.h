/* 
* @Author: sxf
* @Date:   2015-11-05 21:21:50
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 18:46:07
*/


#ifndef META_SCRIPT_RUNNER_H
#define META_SCRIPT_RUNNER_H

#include "ScriptRunner.h"

using namespace std;

namespace OOLUA {
	class Script;
}
class PackageLoader;

/**
 * @brief 元脚本解析器类
 * @details 元脚本是一种编译时脚本, 负责在编译时执行特定动作和用户自定义行为\n
 *          元脚本的首要功能是提供构建语法树的接口, 有此接口, 语法解析器才能在特定的时刻调用元脚本解析器
 *          进行代码生成工作\n
 *          其次, 元脚本具有配置项目环境, 查看编译状态, 控制包导入, 特殊内容输出等诸多功能,
 *          绝大部分功能可以在本子项目中实现\n
 *          本元脚本解析器, 采用lua语言作为脚本, 为了安全的向lua中注册函数, 又引入了oolua
 *          做C++到lua的绑定
 */
class MetaScriptRunner : public ScriptRunner
{
public:
	/**
	 * @brief 初始化脚本解析器
	 */
	virtual void Init();

	/**
	 * @brief 获取语法树根节点
	 * @details 这个设计稍稍有点不好, 仅仅对RedApple后端有效
	 * @return 语法树根节点
	 */
    virtual Node* getRoot(); // 仅支持后端为RedApple的宏翻译系统，其余系统返回NULL

    /**
     * @brief 解析完成后由语法分析器调用
     */
	virtual void Finished();

	/**
	 * @brief 创建默认的脚本解析器
	 */
	static MetaScriptRunner* Create();

	/**
	 * @brief 执行一个lua脚本
	 * 
	 * @param filename 脚本的完整或相对路径
	 * @return 成功为true, 异常为false
	 */
	bool run_file (string const &filename);

	/**
	 * @brief 加载一个脚本, 但暂不执行 (需要pcall才执行)
	 * 
	 * @param filename 脚本的完整或相对路径
	 * @return 成功为true, 异常为false
	 */
	bool load_file (string const &filename);

	/**
	 * @brief 加载一段内存中的lua脚本 (不执行)
	 * 
	 * @param chunk 脚本字符串
	 * @return 成功为true, 异常为false
	 */
	bool load_chunk (string const &chunk);

	/**
	 * @brief 运行一段内存中的lua脚本
	 * 
	 * @param chunk 脚本字符串
	 * @return 成功为true, 异常为false
	 */
	bool run_chunk (string const &chunk);

	void setUpLoader(const string& path);

protected:
	OOLUA::Script* vm;
	Node* root;
	PackageLoader* loader;

	MetaScriptRunner();
	~MetaScriptRunner();
};





#endif // META_SCRIPT_RUNNER_H
