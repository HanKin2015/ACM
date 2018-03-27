/*
author: HanKin
date: 2018/03/21
content: 继承、多态、封装、虚函数、私有公有保护成员、友元函数、重载、重写
枚举、typedef、define、类型占的字符和值范围
Lambda函数、extern
*/

#include <bits/stdc++.h>
using namespace std;

class profession {

};

class student {

public:
private:
protected:

};

enum time {
    first,second,
    third,forth,fifth
};

int vbr;

int main()
{
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    double n = 1e256;
    double m = 172189378912739871237129273891739812;
    cout << n << endl;
    cout << m << endl;

    enum time a = fifth;
    if (a == fifth) {
        cout << a << endl;
    }

    // 当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。定义全局变量时，系统会自动初始化
    int var;
    cout << var << endl;
    cout << vbr << endl;
    return 0;
}
