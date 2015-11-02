/* 
* @Author: sxf
* @Date:   2015-01-03 09:27:52
* @Last Modified by:   sxf
* @Last Modified time: 2015-01-03 09:31:39
*/

#include "Parser.h"
#include "LR_parser.h"

Parser* Parser::NewLRParser()
{
	return new LR_parser();
}