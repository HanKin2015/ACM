#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/**
 * ���庯��division
 * ��������dividend������divisor
 */
int division(int dividend, int divisor)
{
    if(0 == divisor)
	{
        // �׳��쳣���ַ�������������Ϊ0��
		throw string("��������Ϊ0");
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
    // ʹ��try...catch...�����쳣
	try {
	    division(d1, d2);
	}
	catch (string &e) {
	    cout << e << endl;
	}

	return 0;
}
