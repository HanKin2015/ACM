#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    char s[300005];
    int dp[300005][30];
    memset(dp, 0, sizeof(dp));
    cin >> s;
    while(m--) {
        int x, y;
        cin >> x >> y;
        dp[x][s[x - 1]- 'a'] = 1;
        dp[y][s[y - 1]- 'a'] = dp[x][s[y - 1]- 'a'] + 1;
        dp[y][s[x - 1]- 'a'] = dp[x][s[x - 1]- 'a'];
    }

    return 0;
}
