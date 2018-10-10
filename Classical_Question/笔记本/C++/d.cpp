#include <bits/stdc++.h>
using namespace std;

int m, n, maze[1005][1005], ans = -1;
void dfs(int x, int y, int sum)
{
    if(sum > ans) ans = sum;
    if(y == n - 1 || sum < 0) return;
    if(x - 1 >= 0 && y + 1 < n) dfs(x - 1, y + 1, sum + maze[x - 1][y + 1]);
    if(y + 1 < n) dfs(x, y + 1, sum + maze[x][y + 1]);
    if(x + 1 < m && y + 1 < n) dfs(x + 1, y + 1, sum + maze[x + 1][y + 1]);
    return;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maze[i][j] = maze[i][j] * (-1);
            for(int k = 0; k < m; k++) {
                dfs(k, 0, 0);
            }
            maze[i][j] = maze[i][j] * (-1);
        }
    }
    cout << ans << endl;
    return 0;
}
/*
4 3
1 -4 10
3 -2 -1
2 -1 0
0 5 -2
*/