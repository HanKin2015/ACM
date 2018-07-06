/*
组合数：从n中取m个元素的组合方式有多少？
公    式 C(n,m)=n!/((n-m)!*m!)（m≤n）
性质1 C(n,m)= C(n,n-m)
性质2 C(n,m)=C(n-1,m-1)+C(n-1,m)
证明：从m个不同的数中取n个，第m个数如果取的话(包含在n里面)有C(n−1,m−1)种取法，如果不取则有C(n,m−1)种。
lucas （数论定理）
https://www.cnblogs.com/Running-Time/p/4749067.html
*/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{

    int n, m, C[1005][1005];
    for(int i = 1; i < 1005; i++) {
        C[i][i] = C[i][0] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	    C[i][j] %= mod;
        }

    }
    while(cin >> n >> m) {
        cout << C[n][m] % mod << endl;
    }
    return 0;
}
