#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;

int n, sx, sy;
char mat[1005][1005];
int vis[1005][1005], step[1005][1005];
// 4个方向上下左右移动的向量
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void bfs(int sx, int sy)
{
    memset(vis, 0, sizeof(vis));
    step[sx][sy] = 0;
    vis[sx][sy] = 1;
    queue<pair<int, int> > Q;
    Q.push(make_pair(sx, sy));
    while(!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop();
        if(mat[x][y] == '@') {
            cout << step[x][y] << endl;
            break;
        }
        rep(i, 0, 4) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && !vis[next_x][next_y] && (mat[next_x][next_y] == '.' || mat[next_x][next_y] == '@')) {
                Q.push(make_pair(next_x, next_y));
                vis[next_x][next_y] = 1;
                step[next_x][next_y] = step[x][y] + 1;
            }
        }
    }
    return;
}

int main()
{
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> mat[i][j];
            if(mat[i][j] == '*') sx = i, sy = j;
        }
    }
    bfs(sx, sy);
    return 0;
}
