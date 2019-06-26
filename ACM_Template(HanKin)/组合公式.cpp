/*
组合数：从n中取m个元素的组合方式有多少？
公    式 C(n,m)=n!/((n-m)!*m!)（m≤n）
性质1 C(n,m)= C(n,n-m)
性质2 C(n,m)=C(n-1,m-1)+C(n-1,m)
证明：从n个不同的数中取m个，如果取最后一个(即第n个数)作为第m个数，如果取的话有C(n−1,m−1)种取法，如果不取则有C(n-1,m)种。
lucas （数论定理）
https://www.cnblogs.com/Running-Time/p/4749067.html
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int mod = 1e9 + 7;
LL C1[2005][2005];
LL F(int n, int m)    //求组合数
{
    if(C1[n][m]) return C1[n][m];
    if(n < m) return 0;
    if(n == m || m == 0) return 1;
    if(n > m)
        return C1[n][m] = (F(n - 1, m - 1) + F(n - 1, m)) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    static LL C2[2005][2005];  // 组合数
    for(int i = 0; i < 2005; i++) {  // 组合数求法没有问题，只是没有计算C(0,0)=1这种情况。
        C2[i][i] = C2[i][0] = 1;
        for(int j = 1; j < i; j++) {
            C2[i][j] = C2[i - 1][j - 1] + C2[i - 1][j];
            C2[i][j] %= mod;
            if (C2[i][j] != F(i, j)) {
                cout << i << ' ' << j << endl;
            }
        }
    }

    int n, m;
    while (cin >> n >> m) {
        cout << F(n, m) << ' ' << C2[n][m] << endl;
    }
    return 0;
}


