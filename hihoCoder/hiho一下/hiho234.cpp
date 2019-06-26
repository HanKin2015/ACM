#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL N, M, K, R[1005], C[1005];
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) cin >> R[i] >> C[i];

    static LL all[1005][1005];
    for (int i = 1; i < 1005; i++) {     // 单行列画图可得
        all[1][i] = all[i][1] = i * (i + 1) / 2;
    }
    for (int i = 2; i < 1005; i++) {
        for (int j = 2; j < 1005; j++) { // 包含和不包含当前格子：容斥原理
            all[i][j] = all[i - 1][j] + all[i][j - 1] - all[i - 1][j - 1] + i * j;
        }
    }
    //cout << all[2][3] << endl; // 18
    //cout << all[1000][1000] << endl;  这里可能不会超过int范围，在算sum可能会

    for (int i = 1; i < (1 << K); i++) {  // 总共2^K组合
        int cnt = 0;
        LL top = 1005, left = 1005, bottom = -1, right = -1;
        for (int j = 0; j < K; j++) {     // 判断每一位的1
            if (i & (1 << j)) {
                cnt++;
                if (R[j] < top) top = R[j];
                if (R[j] > bottom) bottom = R[j];
                if (C[j] < left) left = C[j];
                if (C[j] > right) right = C[j]; // 从1开始计位
            }
        }
        LL sum = left * top * (N - bottom + 1) * (M - right + 1);
        if (cnt & 1) all[N][M] -= sum;
        else all[N][M] += sum;
    }
    cout << all[N][M] << endl;
    return 0;
}
