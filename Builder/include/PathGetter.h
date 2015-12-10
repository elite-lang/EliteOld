/* 
* @Author: sxf
* @Date:   2015-11-08 11:08:05
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-07 11:29:44
*/

#ifndef PATH_GETTER_H
#define PATH_GETTER_H

#include <string>
using namespace std;

class PathGetter_Private;
class PathGetter
{
public:
	static const char* getEliteHome();
	static const char* getEliteLibPath();
	static const char* getEliteCfgPath();
	static const char* getDefaultLexCfg();
	static const char* getDefaultParserCfg();
	static const char* getNowPath();
	static bool testFile(const char* file);
	static PathGetter_Private* getInstance();
private:
	PathGetter();
	~PathGetter();
	static PathGetter_Private* instance;
};



#endif // PATH_GETTER_H
