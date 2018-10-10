#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define LL long long
using namespace std;

int a[20], t[20];
LL dp[20][20][2];
LL dfs(int len, int cur, int s, int fp)
{
    if(!cur)
        return s;
    if(!fp && dp[len][cur][s] != -1)
        return dp[len][cur][s];
    int n = fp ? a[cur] : 9;
    LL res = 0;
    for(int i = 0; i <= n; i++) {
        t[cur] = i;
        if(len == cur && i == 0)
            res += dfs(len - 1, cur - 1, s, fp && i == n);
        else if(s && cur <= (len + 1) / 2)
            res += dfs(len, cur - 1, t[len - cur + 1] == i, fp && i == n);
        else
            res += dfs(len, cur - 1, s, fp && i == n);
    }
    if(!fp)
        dp[len][cur][s] = res;
    return res;
}
LL sum(LL x)
{
    int len = 0;
    while(x) {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, len, 1, 1);
}

int main(void)
{
    LL a, b;
    while(cin >> a >> b) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        if(a > b) swap(a, b);
        LL all = b - a + 1;
        all = all - sum(b) - sum(a - 1);
        //cout << sum(b) << endl;
        //cout << sum(a - 1) << endl;
        printf("%lld\n", all);
    }

    return 0;
}
