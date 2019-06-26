#include <iostream>
using namespace std;

const int maxn = 1e3 + 5;
int n, m, mat[maxn][maxn];
pair<int, int> pre[maxn][maxn];  // 记录前一步的位置
int dp[maxn][maxn];

void dfs()
{
    return;
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    return 0;
}
