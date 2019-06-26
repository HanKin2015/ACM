#include <bits/stdc++.h>
using namespace std;

// 深搜题记得要把变量写在全局
int N, M;
char mat[505][505];
bool vis[505][505];
int maxX, minX, minY, maxY;
int ans[505][505];

void dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (mat[x][y] == '0' || vis[x][y]) return;  // fuck!!!!先判断边界
    vis[x][y] = true;
    ans[x][y] = 1;
    if (x > maxX) maxX = x;
    if (x < minX) minX = x;
    if (y > maxY) maxY = y;
    if (y < minY) minY = y;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    return;
}

int main()
{
    // 我我我我。。。。下面这段代码为啥不能使用
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));
    bool flag = true;
    for (int i = 0; i < M; i++) {  // 列
        for (int j = 0; j < N; j++) { // 行
            if (mat[j][i] == '1' && !vis[j][i]) {
                flag = false;
                minX = minY = 505;
                maxX = maxY = -1;
                //memset(ans, 0, sizeof(ans));
                dfs(j, i);
                cout << maxX - minX + 1 << ' ' << maxY - minY + 1 << endl;
                for (int p = minX; p <= maxX; p++) {
                    for (int q = minY; q <= maxY; q++) {
                        if (1 == ans[p][q]) {
                            putchar('1');
                            vis[p][q] = true;
                            ans[p][q] = 0;
                        }
                        else {
                            putchar('0');
                        }
                    }
                    puts("");
                }
            }
        }
    }
    if (flag) cout << 0 << ' ' << 0 << endl;
    return 0;
}

/*
5 5
00000
00000
00000
00000
00000

5 5
10001
00000
00100
00000
10001

5 5
11111
11111
11111
11111
11111

5 5
00000
01110
10001
01101
00000

5 5
00000
01110
01010
01110
00000

10 10
0000000000
1010101101
1111001000
0001010000
0010101000
0001111111
1111000000
0000011111
1110001011
0000000000
*/
