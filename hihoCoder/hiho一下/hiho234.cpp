#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL N, M, K, R[1005], C[1005];
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) cin >> R[i] >> C[i];

    static LL all[1005][1005];
    for (int i = 1; i < 1005; i++) {     // �����л�ͼ�ɵ�
        all[1][i] = all[i][1] = i * (i + 1) / 2;
    }
    for (int i = 2; i < 1005; i++) {
        for (int j = 2; j < 1005; j++) { // �����Ͳ�������ǰ���ӣ��ݳ�ԭ��
            all[i][j] = all[i - 1][j] + all[i][j - 1] - all[i - 1][j - 1] + i * j;
        }
    }
    //cout << all[2][3] << endl; // 18
    //cout << all[1000][1000] << endl;  ������ܲ��ᳬ��int��Χ������sum���ܻ�

    for (int i = 1; i < (1 << K); i++) {  // �ܹ�2^K���
        int cnt = 0;
        LL top = 1005, left = 1005, bottom = -1, right = -1;
        for (int j = 0; j < K; j++) {     // �ж�ÿһλ��1
            if (i & (1 << j)) {
                cnt++;
                if (R[j] < top) top = R[j];
                if (R[j] > bottom) bottom = R[j];
                if (C[j] < left) left = C[j];
                if (C[j] > right) right = C[j]; // ��1��ʼ��λ
            }
        }
        LL sum = left * top * (N - bottom + 1) * (M - right + 1);
        if (cnt & 1) all[N][M] -= sum;
        else all[N][M] += sum;
    }
    cout << all[N][M] << endl;
    return 0;
}
