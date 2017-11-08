#include<bits/stdc++.h> // 万能头文件
#include <iostream>
using namespace std;

// 欧几里得算法-辗转相除法
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    // a*b再除以最大公约数就是最小公倍数
    int a = 96, b = 54;
    int gcd1 = gcd(a, b);
    int gcd2 = __gcd(a, b); // 不是标准库函数
    int lcm = a / gcd1 * b; // 先除后乘防止溢出
    cout << gcd1 << endl;
    cout << gcd2 << endl;
    cout << lcm << endl;
    return 0;
}
