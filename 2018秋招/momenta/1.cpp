#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int mod = 1e9 + 7;

bool Judge(int &x, int &y, string s)
{
    bool flag = true;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'D') x--;
        else y--;
        if (!flag || x < 0 || y < 0) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;   // M为列，N为行
        string s1, s2;
        cin >> s1 >> s2;
        LL dp[105][105];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                int x = i, y = j;
                if (Judge(x, y, s1)) dp[i][j] += dp[x][y] + 1;

                x = i, y = j;
                if (Judge(x, y, s2)) dp[i][j] += dp[x][y] + 1;
                dp[i][j] %= mod;
            }
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << dp[N][M] << endl;
    }
    return 0;
}

/*
2
3 2
RRD
DDR
3 2
R
D
*/
