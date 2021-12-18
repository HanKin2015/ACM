#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

// 1、使用transform函数
void use_transform(string str)
{
	// 记得::tolower前面有::,　而且是::tolower, 不是::tolower()

	// 转小写
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout << "转化为小写后为：" << str << endl;
	// 转大写
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	cout << "转化为大写后为：" << str << endl;
	return;
}

// 2、利用ascii码计算得出
void use_mytransform(string str)
{
	size_t len = str.size();
	cout << "len = " << len << endl;

	string s = str;
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;	//+32转换为小写
			//s[i] = s[i] - 'A' + 'a';
		}
	}
	cout << "转化为小写后为：" << s << endl;

	s = str;
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;//+32转换为小写
			//s[i]=s[i]-'a'+'A';
		}
	}
	cout << "转化为大写后为：" << s << endl;
	return;
}

// 3、利用toupper和tolower函数
void use_toupper_tolower(const char *str)
{
	size_t len = strlen(str);
	cout << "len = " << len << endl;

	char *s = new char[len + 1];
	memset(s, 0, len + 1);
	strncpy(s, str, len);
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = tolower(s[i]);
		}
	}
	cout << "转化为小写后为：" << s << endl;

	if (len <= 0) {
		// 消除警告C6385、C6386从..中读取的数据无效: 可读大小为..个字节，但可能读取了..个字节；
		// 写入到..时缓冲区溢出: 可写大小为..个字节，但可能写入了..个字节
		return;
	}
	strncpy(s, str, len);
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = toupper(s[i]);
		}
	}
	cout << "转化为大写后为：" << s << endl;
	return;
}

int main()
{
	string str = "123qweASDzxc";

	cout << "原始含大写的字符串：" << str << endl << endl;

	use_transform(str);
	use_mytransform(str);
	use_toupper_tolower(str.c_str());
	return 0;
}

/*
微软在默认情况下强制对C和C++代码强制使用SAL分析，除了以上两种警告外，还有其他的一些误报（false positive）。

解决方法

#pragma   warning(push)是保存当前的编译器警告状态；
#pragma   warning(pop)是恢复原先的警告状态。
例如：

#pragma warning(push)
#pragma warning(disable:6385)
#pragma warning(disable:6386)
/*Source Code*/
#pragma   warning(pop)  
*/