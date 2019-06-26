#include <bits/stdc++.h>
using namespace std;

int N, M, MAP[805][805], dis[805][805];
bool vis[805][805];
queue<pair<int, int> > Q;
int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 是第一个参数不用写不是第二个
void bfs()
{
    while (!Q.empty()) {
        pair<int, int> loc = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = loc.first + direct[i][0], y = loc.second + direct[i][1];
            if (x < 0 || x >= N || y < 0 || y >= M) continue;
            else {
                dis[x][y] = min(dis[x][y], dis[loc.first][loc.second] + 1);
                if (!vis[x][y]) {
                    Q.push(make_pair(x, y));
                    vis[x][y] = true;
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            MAP[i][j] = c - '0';
            dis[i][j] = 1e7;
            if (MAP[i][j] == 0) {
                Q.push(make_pair(i, j));
                dis[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
