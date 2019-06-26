/*
思路：两个点之间没有边的一定在一个集合里
点的大小就是N
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int G[maxn][maxn];

int main()
{
    int T; cin >> T;
    while (T--) {
        int N, M, X, Y;
        memset(G, 0, sizeof(G));
        int vis[maxn];    // 集合编号
        memset(vis, 0, sizeof(vis));
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> X >> Y;
            G[X][Y] = G[Y][X] = 1;
        }
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0) vis[i] = i;  // 给点添加集合编号，相同编号即在同一个集合
            for (int j = i + 1; j <= N; j++) {
                if (G[i][j] == 0) {  // 没有边就是一个集合
                    if (vis[j] != 0 && vis[j] != vis[i]) {
                        flag = false;
                        //cout << "矛盾：" << i << ' ' << j << endl;
                        break;
                    }
                    vis[j] = i;
                }
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

/*
2
5 7
1 3
1 5
2 3
2 5
3 4
4 5
3 5
4 3
1 2
2 3
3 4
*/
