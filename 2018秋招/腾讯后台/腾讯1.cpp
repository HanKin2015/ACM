/*
1、打表找规律
2、按位找规律
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL GCD(LL a, LL b)
{
    return b ? GCD(b, a % b) : a;
}
LL LCM(LL a, LL b)
{
    a = a / GCD(a, b) * b;
    return a;
}

int main()
{
    int n;
    while (cin >> n) {
        LL a = 1, b = 1;
        for (int i = 1; i <= n; i++) {
            b = LCM(b, i);
        }
        for (int i = n + 1; ; i++) {
            a = LCM(a, i);
            b = LCM(b, i);
            if (a == b) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
