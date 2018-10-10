/*
*迷宫问题
*https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
从左上到右下，1是障碍，0是通道
输入
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;

int N, M, sx, sy, ex, ey;
int mat[105][105];
// 4个方向上下左右移动的向量
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
pair<int, int> last[105][105];  // 记录前一步的最佳位置

void PrintPath(int x, int y)
{
    if(last[x][y].first != -1) {
        PrintPath(last[x][y].first, last[x][y].second);
    }
    printf("(%d, %d)\n", x, y);
    return;
}

int bfs(int sx, int sy, int ex, int ey)
{
    int vis[105][105], step[105][105];   // 记录步数
    memset(vis, 0, sizeof(vis));
    step[sx][sy] = 0;
    vis[sx][sy] = 1;
    last[sx][sy] = make_pair(-1, -1);
    queue<pair<int, int> > Q;
    Q.push(make_pair(sx, sy));
    while(!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop();
        if(x == ex && y == ey) break;
        //rep(i, 0, 4) {
        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !vis[next_x][next_y] && mat[next_x][next_y] == 0) {
                Q.push(make_pair(next_x, next_y));
                vis[next_x][next_y] = 1;
                step[next_x][next_y] = step[x][y] + 1;
                last[next_x][next_y] = make_pair(x, y);
            }
        }
    }
    PrintPath(ex, ey);
    return step[ex][ey];
}

int main()
{
    //cin >> N >> M;
    N = 5, M = 5;
    //rep(i, 0, N) {
    //    rep(j, 0, M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    sx = 0, sy = 0, ex = N - 1, ey = M - 1;
    //cout << bfs(sx, sy, ex, ey) << endl;
    bfs(sx, sy, ex, ey);
    return 0;
}
