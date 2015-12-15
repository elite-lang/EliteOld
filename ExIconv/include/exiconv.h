/* 
* @Author: sxf
* @Date:   2015-11-04 12:07:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-15 09:34:35
*/

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint16_t echar_t;
struct FILE;


/**
 * @brief 将UTF-16的字符串转换为utf8编码，便于输出
 * 
 * @param data UTF-16格式的字符串数组
 * @param outsize 转换后的C字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern char* 
conv2utf8 (const echar_t* data, size_t* outsize);


/**
 * @brief 将utf8编码转换为内部UTF-16格式
 * 
 * @param data C风格字符串数组
 * @param outsize 转换后的UTF-16字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern echar_t*
utf8conv2echar (const char* data, size_t* outsize);




/**
 * @brief 将UTF-16的字符串转换为utf8编码，便于输出
 * 
 * @param data UTF-16格式的字符串数组
 * @param outsize 转换后的C字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern char* 
echar2code (const echar_t* data, size_t* outsize, const char* encode);


/**
 * @brief 将指定编码转换为内部UTF-16格式
 * 
 * @param data C风格字符串数组
 * @param outsize 转换后的UTF-16字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern echar_t*
code2echar (const char* data, size_t* outsize, const char* encode);




/**
 * @brief 自动读取文件下的文本内容，识别文本编码，并自动转换位为UTF-16的内部编码格式
 * 
 * @param f 文件指针，读模式打开
 * @param outsize 转换后的字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern echar_t*
autoreadfile (FILE* f, size_t* outsize);


/**
 * @brief 自动识别文本格式，并转换为内部使用的UTF-16
 * 
 * @param data 传入的字符串原始数据
 * @param outsize 转换后的字符串长度
 * 
 * @return 转换后的字符串，会自动新malloc空间，用过后由调用者释放
 */
extern echar_t*
autoreadchar (const char* data, size_t* outsize);


/**
 * @brief 分析该段字符串的编码
 * 
 * @param data 字符串元数据，必须\0结尾，否则可能异常
 * @return 编码名称，如果为NULL则分析失败
 */
extern const char*
encodedetect (const char* data);

/**
 * @brief 分析该文件的编码
 * 
 * @param data 文件指针
 * @return 编码名称，如果为NULL则分析失败
 */
extern const char*
fileencodedetect (FILE* f);


/**
 * @brief 字符串长度计算
 * 
 * @param str 要测量的字符串，必须0结尾
 * @return 长度
 */
extern size_t
estrlen (const echar_t* str);



#define FreeStr(p) free_str((void**)&p)

extern void
free_str(void** p);

