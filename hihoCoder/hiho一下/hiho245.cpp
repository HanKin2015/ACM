#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int vis[maxn][maxn];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int father[maxn * maxn];

int find(int x)
{
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
int main()
{

    int N;
    cin >> N;
    int cnt = 0, area = 0, perimeter = 0;
    for (int i = 0; i < maxn * maxn; i++) father[i] = i;
    while (N--) {
        int x, y;
        cin >> x >> y;
        // 二维位置转换为一维
        int loc = x * 1000 + y;
        cnt++;
        perimeter += 4;
        area++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (!vis[nx][ny] || nx < 0 || ny < 0 || nx >= 1000 || ny >= 1000) continue;
            int nloc = nx * 1000 + ny;
            int f1 = find(loc), f2 = find(nloc);
            if (f1 != f2) {
                cnt--;
                father[f1] = f2;
            }
            perimeter -= 2;
        }
        cout << cnt << ' ' << area << ' ' << perimeter << endl;
    }
    return 0;
}
