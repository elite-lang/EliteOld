/* 
* @Author: sxf
* @Date:   2015-12-16 12:02:18
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-16 18:14:37
*/

#include <gtest/gtest.h>
#include <string>
#include "estring.h"

using namespace std;

#define __ESTRING_TEST__(name) TEST(EstringTest_##name, name)

__ESTRING_TEST__(Construction)
{
	estring str("您好");
	string hello("您好");
	estring str2(hello);
}


__ESTRING_TEST__(Equal)
{
	estring str("hello您好, 这是一段中英混排");
	string hello("hello您好, 这是一段中英混排");
	estring str2(hello);
	EXPECT_EQ(str == str2, true);
}

__ESTRING_TEST__(ToUtf8)
{
	estring str("我的中国心");
	string hello("我的中国心");
	EXPECT_EQ(str.to_utf8() == hello, true);
}
