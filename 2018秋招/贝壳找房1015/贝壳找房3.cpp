#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
LL dp[1005][1005];

int main()
{
    for (int i = 1; i < 1005; i++) dp[1][i] = 1;
    for (int i = 2; i < 1005; i++) {      // ³¤¶ÈN
        for (int j = 1; j < 1005; j++) {  // Î²ÖµM
            int tmp = sqrt(j);
            for (int k = 1; k <= tmp; k++) {
                if (j % k == 0) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i - 1][j / k];
                    dp[i][j] %= mod;
                }
            }
            if (tmp * tmp == j) {
                dp[i][j] -= dp[i - 1][tmp];
                dp[i][j] %= mod;
            }
        }
    }

    int N, M;
    while (cin >> N >> M) {
        cout << dp[N][M] << endl;
    }
    return 0;
}


