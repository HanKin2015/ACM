/*
˼·��������֮��û�бߵ�һ����һ��������
��Ĵ�С����N
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
        int vis[maxn];    // ���ϱ��
        memset(vis, 0, sizeof(vis));
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> X >> Y;
            G[X][Y] = G[Y][X] = 1;
        }
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0) vis[i] = i;  // ������Ӽ��ϱ�ţ���ͬ��ż���ͬһ������
            for (int j = i + 1; j <= N; j++) {
                if (G[i][j] == 0) {  // û�б߾���һ������
                    if (vis[j] != 0 && vis[j] != vis[i]) {
                        flag = false;
                        //cout << "ì�ܣ�" << i << ' ' << j << endl;
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
