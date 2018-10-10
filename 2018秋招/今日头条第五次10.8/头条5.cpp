#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 2e6 +5;
const int mod = 1e9 + 7;

int dp[maxn], vis[maxn];

int main()
{
    int m, a, b, n, arr;
    cin >> m >> a >> b >> n;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        cin >> arr;
        vis[arr] = 1;
    }

    memset(dp, 0, sizeof(dp));
    for (int i = a; i <= b; i++) {
        if (!vis[i]) dp[i] = 1;
    }
    for (int i = a; i <= m; i++) {
        for (int j = a; j <= b; j++) {
            if (i - j >= 0 && !vis[i - j]) dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[m] << endl;
    return 0;
}


