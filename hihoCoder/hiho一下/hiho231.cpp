/*
...| F | G | F | G |...，其中G为D-F，则脚踩在缝隙上的条件为a*(F+G) < b*L < a*(F+G)+F
化简这个不等式等0 < b*L - a * D < F，即求是否存在整数a, b使得b*L - a*D的差最小且大于0。
b*L - a*D的大于0的最小差值其实就是等于gcd(L, D)，所以gcd(L, D) < F就是脚踩在缝隙上的条件。
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T, F, L, D;
    cin >> T;
    while (T--) {
        cin >> L >> F >> D;
        int G = gcd(L, D);
        if (F > G) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
