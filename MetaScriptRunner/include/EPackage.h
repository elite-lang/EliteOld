/* 
* @Author: sxf
* @Date:   2015-12-24 15:55:11
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-25 15:25:11
*/

#ifndef E_PACKAGE_H
#define E_PACKAGE_H

#include <string>
#include <map>

using namespace std;

class EPackage
{
public:
	EPackage(const string& path, MetaScriptRunner* msr);
	~EPackage();

	/**
	 * @brief 获取包的名字, 该名字是识别这个扩展的唯一标识
	 */
	const string& getName();

	/**
	 * @brief 返回版本号, 格式为字符串
	 */
	const string& getVersion();

	/**
	 * @brief 判断是否是默认载入这个包
	 */
	bool isDefaultLoad();

	/**
	 * @brief 立即加载整个插件
	 * @details 插件的加载方式是, 搜索当前插件路径下的所有可以识别的文件, 进行载入, 但不会递归到下层文件夹
	 */
	void Load();

	/**
	 * @brief 获取当前包的属性值
	 * 
	 * @param name 属性名
	 * @return 对应的值
	 */
	const string& getProp(const string& name);
private:
	map<string, string> props;
	string base_path;
	MetaScriptRunner* msr;

	static string str_null;

	/**
	 * 加载Json配置数据项
	 */
	void loadJson(const string& json);

	void insertProp(const string& name, const string& value);
};



#endif // E_PACKAGE_H
