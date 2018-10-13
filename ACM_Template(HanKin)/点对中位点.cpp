/*
给定n个整数点的坐标，求一个中位整点到所有n点的距离和最小，输出最小距离。
n<=10^5

思路：所有n点的x,y求平均值（错误）
正确的做法：Weiszfeld算法求中位中心
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    double n, x[maxn], y[maxn];
    cin >> n;
    LL sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        sumX += x[i];
        sumY += y[i];
    }
    int X = sumX / n, Y = sumY / n;
    int preX = X, preY = Y;

    while (true) {
        double sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i = 0; i < n; i++) {
            double dis = sqrt((x[i] - X) * (x[i] - X) + (y[i] - Y) * (y[i] - Y));
            sum1 += x[i] / dis;
            sum2 += y[i] / dis;
            sum3 += 1 / dis;
        }
        preX = X, preY = Y;
        X = sum1 / sum3;
        Y = sum2 / sum3;
        if (abs(X - preX) > 2 || abs(Y - preY) > 2) break;
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        double dis = sqrt((x[i] - preX) * (x[i] - preX) + (y[i] - preY) * (y[i] - preY));
        ans += dis;
    }
    cout << ans << endl;
    return 0;
}
/*
样例1:
3
1 1
2 2
3 3
样例2:
5
1 4
2 3
5 2
3 5
4 1

样例1:
2.8284
样例2:
9.6410
*/
