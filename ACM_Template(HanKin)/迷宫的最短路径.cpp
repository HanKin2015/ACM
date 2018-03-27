/*
*����һ����СΪ N��M ���Թ������������ĸ��ͨ���ƶ������������㵽�յ��������С������

N=10, M=10���Թ�����ͼ��ʾ��'#'��'.'��'S'��'G'�ֱ��ʾǽ�ڡ�ͨ���������յ㣩
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

22
*/

#include <iostream>
#include <cstring>
#include <queue>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;

int N, M, sx, sy, ex, ey;
char mat[105][105];
// 4���������������ƶ�������
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
pair<int, int> last[105][105];  //·����¼ǰ����Ȼ��ݹ鵹�����

void PrintPath(int x, int y)  //����ߵ�·��
{
    if(last[x][y].first != -1) {
        PrintPath(last[x][y].first, last[x][y].second);
    }
    printf("(%d,%d)\n", x, y);
    return;
}

int bfs(int sx, int sy, int ex, int ey)
{
    int vis[105][105], step[105][105];
    memset(vis, 0, sizeof(vis));
    step[sx][sy] = 0;
    vis[sx][sy] = 1;
    last[sx][sy] = make_pair(-1, -1);
    queue<pair<int, int> > Q;
    Q.push(make_pair(sx, sy));
    while(!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop();
        if(x == ex && y == ey) break;
        rep(i, 0, 4) {
            int next_x = x + dx[i], next_y = y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !vis[next_x][next_y] && mat[next_x][next_y] == '.') {
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
    cin >> N >> M;
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> mat[i][j];
            if(mat[i][j] == 'S') sx = i, sy = j;
            if(mat[i][j] == 'G') ex = i, ey = j, mat[i][j] = '.';
        }
    }
    cout << bfs(sx, sy, ex, ey) << endl;
    return 0;
}
