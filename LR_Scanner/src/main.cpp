/* 
* @Author: sxf
* @Date:   2015-04-14 14:38:22
* @Last Modified by:   sxf
* @Last Modified time: 2015-04-21 16:24:55
*/

#include "afx.h"
#include <stdio.h>
#include <iostream>
#include "help_message.h"
#include "Lex.h"
#include <fstream>
#include "Parser.h"
#include <unistd.h>


#define maxpath 1000
using namespace std;  

CHAR* fileReader(const char* path, int& flen) {
    wfstream file;
    locale::global(locale("zh_CN.UTF-8"));
    file.open(path);//打开文件
    if(!file.is_open())
    {
        printf("can not open BNF file!\n");
        return NULL;
    }
    file.seekg(0,ios::end);
    flen = file.tellg();
    file.seekg(0,ios::beg);
    CHAR* data = new CHAR[flen+1];
    file.read(data,flen);
    file.close();
    data[flen] = 0;
    printf("========= file reader ========\n");
    printf("file length:%d\n",flen);
//     分配数据空间
    printf("%S",data);
//    for (int i = 0; i< flen; ++i)
//        printf("%C",data[i]);
    printf("==============================\n");
    return data;
}

int main(int argc,const char *argv[])
{
	char buffer[maxpath]; int flen;
    getcwd(buffer, sizeof(buffer));
    
	
	if (argc <= 1) printf(help_message);
	else {
		/* init lex */
		Lex* lexParser = new Lex();
	    Parser* parser = Parser::NewLRParser();
	    parser->setLex(lexParser);

	    const char *file_in_name = argv[1];

		CHAR* data = fileReader(file_in_name,flen);
	    if (data == NULL) {
	        printf(file_in_name);
	        printf("找不到程序源文件");
	        return -1;
	    }
	    
	    bool b = lexParser->ReadConfig("lex.txt");
	    lexParser->Init(data);
	    printf("lex done.\n");
	    parser->BuildParser("lrparser.txt");
	    printf("parser done.\n");
	    Grammer_Node* root = new Grammer_Node();
	    parser->Parse(root);
	}
	return 0;
}

