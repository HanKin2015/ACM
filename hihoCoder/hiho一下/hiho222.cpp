/*
思路：暴力搜索
时间复杂度：O(N^3)

经典的优化技巧：前缀和。
时间复杂度：O(N^2)
先预处理计算以(i,j)为中心的上下左右的连续1的个数。
*/
#include <bits/stdc++.h>
using namespace std;

int N, mat[505][505];
bool Judge(int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < N) {
        if (mat[x][y] == 1) return true;
    }
    return false;
}

int main()
{
    cin >> N;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            mat[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool flag = true;
            for (int k = 0; k <= N / 2; k++) {
                int x1 = i - k, y1 = j;
                int x2 = i + k, y2 = j;
                int x3 = i, y3 = j - k;
                int x4 = i, y4 = j + k;
                if (Judge(x1, y1) && Judge(x2, y2) && Judge(x3, y3) && Judge(x4, y4)) continue;
                else {
                    if (k - 1 > ans) ans = k - 1;
                    flag = false;
                    break;
                }
            }
            if (flag && N / 2 > ans) ans = N / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
1
1

2
11
11

8
11111111
11111111
11111111
11111111
11111111
11111111
11111111
11111111
*/
