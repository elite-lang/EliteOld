/* 
* @Author: sxf
* @Date:   2015-12-15 09:43:18
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 22:33:12
*/
#ifndef ESTRING_H
#define ESTRING_H

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>


typedef uint16_t echar_t;

/**
 * @brief 内部使用utf16LE编码的字符串类, 能够实现编码的字符识别和转换
 */
class estring
{
public:
	typedef std::basic_string<echar_t>::iterator iterator;

	estring();
	estring(const std::string& str);
	estring(const estring& estr);
	estring(const char* cstr);
	estring(const echar_t* ecstr);
	~estring();

	void autoreadfile(const std::string& path);
	void autoreadstr(const std::string& str);
	void readfile(const std::string& path, const std::string& encode);
	void readstr (const std::string& str,  const std::string& encode);
	void readstr (const char* data,  const std::string& encode);

	echar_t& operator[] (size_t k);
	const echar_t& operator[] (size_t k) const;
	const estring& operator= (const estring& estr);
	const estring& operator= (const std::string& str);
	const estring& operator= (const char* cstr);
	const estring& operator= (const echar_t* ecstr);
	bool operator== (const estring& estr);

	// const char* c_str();
	const echar_t* ec_str();

	std::string to_utf8();
	std::string to_str(const std::string& encode);

	int find(echar_t c) const;
	int length() const;

	void clear();
	void append(echar_t c);

	/**
	 * @brief 返回一个子串, 从begin开始, 数size个
	 * 
	 * @param begin 开始位置
	 * @param size 子串长度
	 * 
	 * @return 子串的estring对象
	 */
	estring substr(int begin, int size);

	static const char* encodedetect (const char* data);

	iterator begin();
	iterator end();
	void push_back(echar_t c);

private:
	static std::string load_full_file(const std::string& path);

	std::basic_string<echar_t> data;

};






#endif // ESTRING_H
