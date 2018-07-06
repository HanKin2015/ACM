#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define maxn 200005
#define mod 20180520
using namespace std;

map<pair<int, int>, int> vis;
void bfs(int n, int m, queue<pair<int, int> > &Q, int step[505][505])
{
    //int vis[505][505];
    //memset(vis, 0, sizeof(vis));
    while(!Q.empty()) {
        pair<int, int> pos = Q.front();
        Q.pop();
        int x = pos.first, y = pos.second;
        //cout << x << y << endl;
        //vis[pos] = 1;  //here is wrong, if do as it, there is same position insert.
        if(y > 0) {
            step[x][y - 1] = min(step[x][y - 1], step[x][y] + 1);
            pair<int, int> cur = make_pair(x, y - 1);
            if(vis[cur] != 1) Q.push(cur), vis[cur] = 1;
        }
        if(y < m - 1) {
            step[x][y + 1] = min(step[x][y + 1], step[x][y] + 1);
            pair<int, int> cur = make_pair(x, y + 1);
            if(vis[cur] != 1) Q.push(cur), vis[cur] = 1;
        }
        if(x > 0) {
            step[x - 1][y] = min(step[x - 1][y], step[x][y] + 1);
            pair<int, int> cur = make_pair(x - 1, y);
            if(vis[cur] != 1) Q.push(cur), vis[cur] = 1;
        }
        if(x < n - 1) {
            step[x + 1][y] = min(step[x + 1][y], step[x][y] + 1);
            pair<int, int> cur = make_pair(x + 1, y);
            if(vis[cur] != 1) Q.push(cur), vis[cur] = 1;
        }
    }
    vis.clear();
    return;
}

int main() {
	int n, m;
	while(cin >> n >> m) {
        int mat[505][505];
        queue<pair<int, int> > Q;
        while(!Q.empty()) Q.pop();
        int step[505][505];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == 1) {
                    vis[make_pair(i, j)] = 1;
                    Q.push(make_pair(i, j));
                    step[i][j] = 0;
                }
                else step[i][j] = maxn;
            }
        }
        bfs(n, m, Q, step);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d%c", step[i][j], j < m - 1 ? ' ' : '\n');
            }
        }
	}
	return 0;
}

/*
2 3
0 0 0
1 0 1

1 2 1
0 1 0

4 4
0 0 0 0
1 0 0 0
0 0 0 0
0 0 0 0

1 2 3 4
0 1 2 3
1 2 3 4
2 3 4 5


4 4
1 1 1 1
1 1 0 0
0 0 1 0
0 0 0 0

0 0 0 0
0 0 1 1
1 1 0 1
2 2 1 2

3 6
0 0 1 0 0 0
1 0 0 0 0 1
0 0 0 0 0 0

*/
