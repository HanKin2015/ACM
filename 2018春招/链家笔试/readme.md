# 输入1-100之间没有重复的数，输出漏写的数。
hash记录已经出现的数字，遍历100以内的数。

# 一个开关控制多个灯泡的点亮(没有熄灭功能)，问最多点亮多少灯泡？
set容器去重输出即可。

```
作者：FlushHip
链接：https://www.nowcoder.com/discuss/72602?type=0&order=0&page=0
来源：牛客网

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    for (int n; cin >> n; ) {
        set<int> st;
        for (int i = 0, k; i < n; i++) {
            cin >> k;
            for (int j = 0, x; j < k; j++)
                cin >> x, st.insert(x);
        }
        cout << st.size() << endl;
    }
    return 0;
}
```

# 输入n，问最少去掉1-n之间的多少个数字使剩下的数字无法形成三角形？
剩下的数字满足斐波那契数列。如1，2，3，5，8，13。。。

```
#include <bits/stdc++.h>
 
using namespace std;
 
#define TOP 100000
 
int main()
{
    vector<int> dp(3);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; dp[i - 1] + dp[i - 2] <= TOP; i++)
        dp.push_back(dp[i - 1] + dp[i - 2]);
    for (int n; cin >> n; ) {
        auto it = lower_bound(dp.begin(), dp.end(), n);
        cout << *it - (it - dp.begin()) - (*it == n ? 0 : *it - n - 1)<< endl;
    }
    return 0;
}
```



