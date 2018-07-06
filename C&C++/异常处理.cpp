#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/**
 * 定义函数division
 * 参数整型dividend、整型divisor
 */
int division(int dividend, int divisor)
{
    if(0 == divisor)
	{
        // 抛出异常，字符串“除数不能为0”
		throw string("除数不能为0");
	}
	else
	{
		return dividend / divisor;
	}
}

int main(void)
{
	int d1 = 0;
	int d2 = 0;
	int r = 0;
	cin >> d1;
	cin >> d2;
    // 使用try...catch...捕获异常
	try {
	    division(d1, d2);
	}
	catch (string &e) {
	    cout << e << endl;
	}

	return 0;
}
