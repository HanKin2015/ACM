/*
锯木头，给出多棵树的高度(n<=10^5)，想要总和长度为m(m<=10^9)的树头，问需要在树的最高位置哪里能满足要求？

二分答案。
时间复杂度：O(log10^9*10^5)
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    LL n, m, a[maxn];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(a[i] - mid, 0LL);
        }
        if (sum == m) break;
        else if (sum > m) l = mid + 1;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
/*
5 20
4 42 40 26 46
*/
