/*
* @Author: sxf
* @Date:   2015-12-24 15:55:11
* @Last Modified by:   sxf
* @Last Modified time: 2016-01-01 13:28:11
*/

#ifndef E_PACKAGE_H
#define E_PACKAGE_H

#include <string>
#include <map>

using namespace std;

class MetaScriptRunner;

/**
 * @brief Elite的软件包扩展
 * @details 这个类是Elite的插件元数据类，每个软件包都会有一个package.json配置
 *          本类负责解析配置数据，存储软件包的各关键路径，加载或卸载该软件包
 *          也可以获取到软件包相关的重要配置参数信息，例如名字、版本、是否加载等信息。
 */
class EPackage
{
public:
	/**
	 * @brief 软件包的构造函数
	 * @details 构造一个插件包时，当前路径需要被确定校验存在，并含有一个package.json的元数据配置项
	 *          构造中，会解析package.json的相关数据，但不会加载其他任何内容
	 *          对于自动加载型的插件包，需要在外层再扫描一次，判断并加载。
	 *
	 * @param path 当前软件包的路径，应为绝对路径
	 * @param msr 当前MetaScriptRunner的指针，加载时，可能会加载lua脚本，或者epbc二进制码，该接口负责调用对应功能
	 */
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
	 * @brief 获取一个Runtime时添加链接的字符串
	 */
	const string& getRuntime();

	/**
	 * @brief 判断是否是默认载入这个包
	 */
	const bool isDefaultLoad();

	/**
	 * @brief 判断这个包能否在本平台环境下被载入
	 */
	const bool canLoadOnPlatform();

	/**
	 * @brief 判断这个软包是否已经加载
	 */
	const bool isLoaded();

	/**
	 * @brief 立即加载整个插件
	 * @details 插件的加载方式是, 搜索当前插件路径下的所有可以识别的文件, 进行载入, 但不会递归到下层文件夹
	 */
	void Load();


	void Run();

	/**
	 * @brief 获取当前包的属性值
	 *
	 * @param name 属性名
	 * @return 对应的值
	 */
	const string& getProp(const string& name);

	static string str_null;

private:
	map<string, string> props;
	string base_path;
	MetaScriptRunner* msr;

	/**
	 * 加载Json配置数据项
	 * @param json 一段JSON字符串数据
	 */
	void loadJson(const string& json);

	/**
	 * @brief 向当前插件包中添加新的属性
	 *
	 * @param name 属性名
	 * @param value 属性值
	 */
	void insertProp(const string& name, const string& value);


	/**
	 * @brief 为runtime属性添加-L寻找路径，否则会造成库找不到.
	 *        这个函数仅在构造函数中调用一次, 不能多次调用
	 */
	void addRuntimePath();
};



#endif // E_PACKAGE_H
