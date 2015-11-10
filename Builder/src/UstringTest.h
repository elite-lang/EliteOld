/* 
* @Author: sxf
* @Date:   2015-11-08 13:33:56
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-08 13:55:41
*/

#ifndef USTRING_TEST_H
#define USTRING_TEST_H

#include <glibmm.h>
#include <iostream>

using namespace std;

class UstringTest
{
public:
	static void Test1() {
		Glib::ustring str = "你好啊";
		cout << str.c_str() << endl;
	}
	
	static void Test2() {
		Glib::ustring str = "你好啊abc哈哈";
		str.append(2, str[0]);
		cout << str.c_str() << endl;
		cout << str.size() << endl;
		cout << str[0] << endl;
	}
};




#endif // USTRING_TEST_H
