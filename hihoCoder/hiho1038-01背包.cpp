#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int need[505], value[505], dp[500005];
    memset(dp, 0, sizeof(dp));
    int ans = -1;
    for(int i = 0; i < N; i++) {
        cin >> need[i] >> value[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = M; j >= need[i]; j--) {
            dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
    /*���������û����ԭʼ��01��������ȥ�⣬û����ô�������
    int f[N][M];
    f[i][j] = max(f[i - 1][j - W[i]] + P[i], f[i - 1][j]);//j >= W[ i ]
    */
    return 0;
}

