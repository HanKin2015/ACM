/*
|0 1| |F0| = |F1|
|1 1| |F1|   |F2|
or
|F0 F1||0 1| = |F1 F2|
|0   0||1 1|   |0   0|
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// 矩阵相乘
void mul(int a[4], int b[4])
{
    int ret[4];
    ret[0] = a[0] * b[0] + a[1] * b[2];
    ret[1] = a[0] * b[1] + a[1] * b[3];
    ret[2] = a[2] * b[0] + a[3] * b[2];
    ret[3] = a[2] * b[1] + a[3] * b[3];
    for (int i = 0; i < 4; i++) a[i] = ret[i] % mod;
    return;
}

// 矩阵模快速幂解决斐波那契数列
int Fibonacci(int n)
{
    int ret[4] = {1, 0, 0, 1}, tmp[4] = {0, 1, 1, 1};
    while (n) {
        if (n & 1) mul(ret, tmp);
        mul(tmp, tmp);
        n >>= 1;
    }
    return ret[1];
}

int main()
{
    int n;
    while (cin >> n) {
        cout << Fibonacci(n) << endl;
    }
    return 0;
}
