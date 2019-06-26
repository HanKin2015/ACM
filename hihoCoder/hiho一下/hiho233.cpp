#include <bits/stdc++.h>
#define LL long long
using namespace std;

map<LL, LL> HASH;

int main()
{
    const int maxn = 1e5 + 5, mod = 1e9 + 7;
    int N, A;
    LL sum[maxn];
    cin >> N;
    //static int HASH[10000005];
    //memset(HASH, 0, sizeof(HASH));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++) {
        cin >> A;
        sum[i] = sum[i - 1] + A;
        //HASH[sum[i]]++;  写在这里有个问题就是会把后面的也算上
    }

    LL dp;  // dp[0]即数组本身
    LL dp_sum[maxn] = {1};
    HASH[0] = 1;  // 当整个本身为0
    for (int i = 1; i <= N; i++) {
//        for (int j = i - 1; j >= 0; j--) {
//            if (sum[i] - sum[j] != 0) {
//                dp[i] += dp[j];
//                dp[i] %= mod;
//            }
//        }
        dp = (dp_sum[i - 1] - HASH[sum[i]] + mod) % mod;
        dp_sum[i] = dp_sum[i - 1] + dp;
        HASH[sum[i]] += dp;
        //cout << i << ' ' << dp[i] << endl;
    }
    cout << dp << endl;
    return 0;
}

/*
10
-1 1 1 -2 -4 3 2 2 -5 2

10
-1 1 2 -2 -4 3 2 2 -5 2

10
-1 1 2 -2 -4 3 2 3 -5 2
*/
