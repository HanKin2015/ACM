/*
思考：原先是序列，各不相同，按从小到大排序。

所以，最小两个数肯定最小，最大两个数和最大。

做不出来，还是参考吧：https://www.cnblogs.com/ymzjj/p/10294659.html
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int maxn = 1e5 + 5;
using LL = long long;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, b[100005];
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int a[305], dex = 0;
        bool flag = true;
        for (int i = 3; i <= n; i++) {
            int tmp = b[1] + b[2] - b[3];
            if (tmp & 1) {

            }
            a[1] = tmp / 2;
            a[2] = b[1] - a[1];
            a[3] = b[2] - a[1];
            dex = 4;
            b[i] = 0;
            set<int> S;
            S.insert(a[1]);
            S.insert(a[2]);
            S.insert(a[3]);
            for (int j = 3; j <= n; j++) {
                if (b[j]) {
                    for (int num : S) {
                        int temp = b[j] - num;
                        auto it = S.find(temp);
                        if (it == S.end()) {
                            a[dex++] = temp;
                        }
                    }
                    S.insert(b[j] - )
                }
            }
        }
    }
	return 0;
}

