#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e3 +5;

int mat[maxn][maxn], dp[maxn][maxn];
int vis[maxn][maxn];

int main()
{
    int k;
    cin >> k;
    string str;
    int row = 0;
    while (cin >> str) {
        int num = 0, cnt = 0;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == ',') {
                mat[row][cnt++] = num;
                num = 0;
            }
            else if (str[j] == '-') num = -2;
            else num += str[j] - '0';
        }
        mat[row][cnt++] = num;
        row++;
    }

    int sumOut = 0, x[maxn], y[maxn];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            //cout << mat[i][j] << ' ';
            if (mat[i][j] == 1) {
                x[sumOut] = i;
                y[sumOut++] = j;
            }
        }
        //cout << endl;
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            dp[i][j] = maxn;
        }
    }


    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < sumOut; i++) {
        dp[x[i]][y[i]] = 0;
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(x[i] * maxn + y[i]);
        while (!Q.empty()) {
            int pos = Q.front();
            Q.pop();
            int posX = pos / maxn, posY = pos % maxn;
            vis[posX][posY] = 1;
            for (int j = 0; j < 4; j++) {
                int newX = posX + direct[j][0];
                int newY = posY + direct[j][1];
                if (newX >= 0 && newX < row && newY >= 0 && newY < row && mat[newX][newY] != -1) {
                    dp[newX][newY] = min(dp[newX][newY], dp[posX][posY] + 1);
                    if (!vis[newX][newY]) Q.push(newX * maxn + newY);
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (mat[i][j] == -1) cout << 0;
            else if (dp[i][j] <= k) cout << 0;
            else cout << 1;
            if (j != row - 1) cout << ',';
        }
        cout << endl;
    }
    return 0;
}
/*
3
0,-1,1,0
0,0,0,-1
0,-1,0,-1
1,-1,0,0
*/



