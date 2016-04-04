/*
* @Author: sxf
* @Date:   2015-12-21 20:35:05
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 15:54:44
*/


#ifndef DEBUG_MSG_H
#define DEBUG_MSG_H

#include <fstream>
using namespace std;

class DebugMsg_Private;

/**
 * @brief debug信息单例类
 */
class DebugMsg
{
public:
	/**
     * @brief 设置解释器生成中间变量的目录，设置后自动打印中间过程
     *
     * @param path 设置路径，设置为NULL或不设置则不打印过程
     */
    static void setDebugFilePath(const char* path);

    /**
     * @brief 判断是否Debug模式
     */
    static bool isDebug();

    /**
     * @brief 获取词法分析器的debug文件输出流
     */
    static std::ostream& lex_dbg();
    static void lex_close();

    static std::ostream& lex_save();
    static void lex_save_close();
    /**
     * @brief 获取解析器的debug输出文件流
     */
    static std::ostream& parser_dbg();
    static void parser_close();

    static std::ostream& parser_save();
    static void parser_save_close();

    /**
     * @brief 获取解析器的debug输出文件流
     */
    static std::ostream& red_dbg();
    static void red_close();

    static std::ostream& red_llvm_bc();
    static void red_llvm_bc_close();

    static std::ostream& lex_graphviz();
    static void lex_graphviz_close();

    static std::ostream& parser_graphviz();
    static void parser_graphviz_close();

	static DebugMsg_Private* getInstance();
private:
	static DebugMsg_Private* instance;
};



#endif // DEBUG_MSG_H
