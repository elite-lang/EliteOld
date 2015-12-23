/* 
* @Author: sxf
* @Date:   2015-12-07 10:43:17
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 08:37:56
*/

#include "elite-config.h"

const char* help_message = 
	"欢迎使用精锐编译器" ELITE_RELEASE "版\r\n"
	"Welcome to use " ELITE_RELEASE "\r\n\r\n"
	"----------------------------------------------------------\r\n"
	"-h/--help\t\t打印帮助信息 / Print help message\r\n"
	"-s/--src <path>\t\t指定源程序路径 / Set the source file path\r\n"
	"-d/--dir <path>\t\t指定输出文件路径 / Set the output file path\r\n"
	"--show\t\t\t展示模式 / Show Mode\r\n"
	"-c\t\t\t仅编译不链接 / Only compile files without link\r\n"
	"-i/--in <file>\t\t单独编译一个文件 / Compiler only one file\r\n"
	"-l/--lex <*.cfg>\t指定词法配置 / Set the lex config file\r\n"
	"-p/--parser <*.cfg>\t指定语法配置 / Set the parser config file\r\n"
	"----------------------------------------------------------\r\n\r\n"
	;