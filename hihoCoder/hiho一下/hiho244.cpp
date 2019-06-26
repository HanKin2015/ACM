#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int status = 1 << m;  // 所有属性的组合，取或者不取，用二进制表示状态，即状态压缩
        static int f[1005][1 << 11]; // 表示从前i个物品中选出若干个，属性奇偶性是s的情况下能达到的最高价值
        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int v, s, st = 0;
            cin >> v >> s;
            for (int j = 0; j < s; j++) {
                int attr;
                cin >> attr;
                st |= 1 << (attr - 1);  // 把每个物品拥有的属性位置值为1，无的为0
            }
            for (int t = 0; t < status; t++) {
                if (!f[i - 1][t]) {
                    // 取当前物品，奇偶性发生变化。应该异或
                    f[i][t ^ st] = max(f[i][t ^ st], f[i - 1][t] + v);
                    // 不取当前物品
                    f[i][t] = max(f[i][t], f[i - 1][t]);
                    //f[i][t | st] = max(f[i - 1][t | st], f[i - 1][t] + v);
                }
            }
        }
        cout << max(f[n][status - 1], 0) << endl;
     }
    return 0;
}
