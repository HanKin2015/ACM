#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int N;
    cin >> N;
    int MAP[55][55];
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            MAP[i][j] = s[j] - '0';
        }
    }
    int dp[55][55];
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            dp[i][j] = mod;
        }
    }
    int direct[8][2] = {{-2, -2}, {2, 2}, {-2, 2}, {2, -2}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int vis[55][55];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N - 1 && j == N - 1) break;
            vis[i][j] = 1;
            if (dp[i][j] == mod) dp[i][j] = 0;
            if (MAP[i][j] == 1) continue;
            for (int k = 0; k < 8; k++) {
                int x = i + direct[k][0], y = j + direct[k][1];
                if (x >= 0 && x < N && y >= 0 && y < N && MAP[x][y] != 1) {
                    if (MAP[x][y] == 2) dp[x][y] = min(dp[i][j] + 2, dp[x][y]);
                    else dp[x][y] = min(dp[i][j] + 1, dp[x][y]);
                }
            }
        }
    }
    if (dp[N - 1][N - 1] != mod) cout << dp[N - 1][N - 1] << endl;
    else cout << "Impossible" << endl;
    return 0;
}

/*
ÑùÀý1:
4
0000
0000
0000
0000
ÑùÀý2:
4
0111
1111
1111
1110
*/

