/*
* @Author: sxf
* @Date:   2015-12-16 12:02:18
* @Last Modified by:   sxf
* @Last Modified time: 2016-05-10 16:30:40
*/
#ifdef __APPLE__
#define GTEST_HAS_POSIX_RE 0
#endif

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

__ESTRING_TEST__(Select)
{
	estring str("您好hello");
	for (int i = 0; i < 7; ++i)
		printf("%04X ", str[i]);
	printf("\n");
	EXPECT_EQ(str[3], 'e');
}

__ESTRING_TEST__(Select2)
{
	estring str("0-9");
	EXPECT_EQ(str[0], '0');
	EXPECT_EQ(str[1], '-');
	EXPECT_EQ(str[2], '9');
}

__ESTRING_TEST__(Enter)
{
	estring str("hello\n您好, 这是一段中英混排\n"
		"这里稍稍有点问题"
		"so, I\n want to have a try."
		);
	EXPECT_EQ(str[5], '\n');
	EXPECT_EQ(str[18], '\n');
	int i = 19;
	while(i < str.length()) {
        if (str[i] == '\n') break;
        ++i;
    }
    estring substr = str.substr(19, i-19); // 注意, substr的第二个参数需要的是长度, 而不是到哪里
    printf("%s\n",substr.to_utf8().c_str());
    estring ans = "这里稍稍有点问题so, I";
    EXPECT_EQ(substr==ans, true);
}


__ESTRING_TEST__(Construction2AndFind)
{
	estring str("hello您好, 这是一段中英混排");
	estring estr(str.ec_str());
	EXPECT_EQ(str==estr, true);
	EXPECT_EQ(str.find('l'), 2);
}
