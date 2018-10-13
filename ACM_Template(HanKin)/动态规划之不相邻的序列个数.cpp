/*
给定n个不同的数(n<=100)，不相邻的选取，问有多少方案？

如果有重复的数字，则可以进行排序。
按道理来说没有吧，暴力搜索。
时间复杂度：O(2^100)

使用动态规划：dp[i]当前i位置的方案数量
状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
选择i位置的就dp[i-2]不选择i位置就是dp[i-1]
不会有重复啊，i-1位置的1就只有1，而i-2位置的1还会加上i，即1 i。
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[105], dp[105] = {0, 2, 3, 5, 8,13};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
    return 0;
}
/*
1 2 3 4 5

1
2
3
4
5
1 3
1 4
1 5
2 4
2 5
3 5
1 3 5

12

2 3 5 8 13
*/
