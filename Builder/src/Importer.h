/* 
* @Author: sxf
* @Date:   2015-11-08 09:02:23
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 09:06:23
*/


#ifndef IMPORTER_H
#define IMPORTER_H

#include <string>

using namespace std;

/**
 * @brief 包导入器
 */

class Importer
{
public:
	Importer();
	~Importer();
	
	int import(string& name);
};



#endif // IMPORTER_H
