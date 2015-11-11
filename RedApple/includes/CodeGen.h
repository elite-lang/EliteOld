/* 
* @Author: sxf
* @Date:   2015-11-11 13:57:49
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-11 16:47:26
*/


#ifndef CODE_GEN_H
#define CODE_GEN_H

class CodeGen
{
public:
	virtual void Make(const char* outfile_name) = 0;
};

#endif // CODE_GEN_H
