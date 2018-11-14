#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct SAMPLE {
    int cnt[2];
    SAMPLE(int cntPos = 0, int cntNeg = 0) {
        cnt[0] = cntPos;
        cnt[1] = cntNeg;
    }
};

int main()
{
    int n, x, y, cnt[2] = {0}, max_x = -1;
    SAMPLE sam[maxn];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &x, &y);
        cnt[y]++;
        sam[x].cnt[y]++;
        if (x > max_x) x = max_x;
    }
    double p = cnt[0] * 1.0 / n, q = cnt[1] * 1.0 / n;
    double E = -p * log2(p) - q * log2(q);      // 整体熵

    for (int i = 0; i <= max_x; i++) {
        int _n = sam[i].cnt[0] + sam[i].cnt[1];
        double _p = sam[i].cnt[0] * 1.0 / _n, _q = sam[i].cnt[1] * 1.0 / _n;
        double _E = -_p * log2(_p) - _q * log2(_q);      // 单变量熵
        E -= (_n * 1.0 / n) * _E;
    }

    printf("%.2f\n", E);
    return 0;
}

/*
5
1,1
1,1
2,0
0,0
3,0
*/
