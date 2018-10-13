/*
组合数公式：C(n, m) = C(n - 1, m - 1) + C(n - 1, m)
C(n, m) = C(n, n - m)
推理：跟N个硬币放进M个存钱罐有多少种存放方式分析过程一样(考虑是否全部都有钱)
现在考虑从n个人中选择m个，那么有两种情况：
1. 第n个人选进去，那么就是从剩下的n-1个人中选择m-1个，再加上第n个组成；
2. 第n个人不选进去，那么就是直接从n-1个人中选择m个。


排列数公式：A(n, m) =

stirling数(斯特林数)

Catalan数(卡特兰数)

*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int C[maxn][maxn];

int main()
{
    for (int i = 0; i < maxn; i++) C[i][0] = 1;  // 其他默认0
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    cout << C[5][3] << endl;   // 10
    return 0;
}
