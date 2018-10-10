// dp[M][A][R] =
// dp[M][1][R] = M < R ? M : R;   // ¸öÊý
// 0%

#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e3 + 5;

LL POW(int n, int x)
{
    LL res = 1;
    for (int i = 0; i < x; i++) {
        res *= n;
    }
    return res;
}

int main()
{
    int M, A, R;
    cin >> M >> A >> R;
    M = (M < R ? M : R);
    double ans = (M * A) * 1.0 / POW(R, A);
    printf("%.5f\n", ans);
    return 0;
}


