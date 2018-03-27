#include <iostream>
#include <cstring>
#include <queue>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;

int N, M;
char mat[105][105];
// 4个方向上下左右移动的向量
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
struct node {
    int people_x, people_y, box_x, box_y;
    node(int _people_x, int _people_y, int _box_x, int _box_y) {
        people_x = _people_x, people_y = _people_y;
        box_x = _box_x, box_y = _box_y;
    }
};

int bfs(int people_x, int people_y, int box_x, int box_y)
{
    //迷宫问题是二维，记录人即可。推箱子需要考虑人和箱子的每个状态四维，没区别
    int vis[10][10][10][10], step[10][10][10][10];
    memset(vis, 0, sizeof(vis));
    step[people_x][people_y][box_x][box_y] = 0;
    vis[people_x][people_y][box_x][box_y] = 1;
    queue<node> Q;
    node cur(people_x, people_y, box_x, box_y);
    Q.push(cur);
    while(!Q.empty()) {
        cur = Q.front(); Q.pop();
        //printf("(%d, %d) (%d, %d)\n", cur.people_x, cur.people_y, cur.box_x, cur.box_y);
        if(mat[cur.box_x][cur.box_y] == '@') return step[cur.people_x][cur.people_y][cur.box_x][cur.box_y];
        rep(i, 0, 4) {
            int next_px = cur.people_x + dx[i], next_py = cur.people_y + dy[i];
            int next_bx = cur.box_x, next_by = cur.box_y;
            if(next_px == cur.box_x && next_py == cur.box_y) {
                next_bx += dx[i], next_by += dy[i];
            }
            if(next_px >= 0 && next_py >= 0 && next_px < N && next_py < M && \
               next_bx >= 0 && next_by >= 0 && next_bx < N && next_by < M && \
               !vis[next_px][next_py][next_bx][next_by] && mat[next_px][next_py] \
               != '#' && mat[next_bx][next_by] != '#') {
                Q.push(node(next_px, next_py, next_bx, next_by));
                vis[next_px][next_py][next_bx][next_by] = 1;
                step[next_px][next_py][next_bx][next_by] = step[cur.people_x][cur.people_y][cur.box_x][cur.box_y] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int people_x, people_y, box_x, box_y;
    cin >> N >> M;
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> mat[i][j];
            if(mat[i][j] == 'X') {
                people_x = i;
                people_y = j;
            }
            if(mat[i][j] == '*') {
                box_x = i;
                box_y = j;
            }
        }
    }
    cout << bfs(people_x, people_y, box_x, box_y) << endl;
    return 0;
}

/*
4 4
....
..*@
....
.X..

3

6 6
...#..
......
#*##..
..##.#
..X...
.@#...

11
*/
