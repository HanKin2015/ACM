#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int maxn = 1e5 + 5;
using LL = long long;

int main()
{
    //freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a[7];
        LL sum = 0;
        for (int i = 1; i <= 6; i++) {
            cin >> a[i];
            sum += a[i];
        }
        double ans = 0;
        for (int i = 1; i <= 6; i++) {
            double tmp = a[i] * 1.0 / sum * i;
            if (tmp > ans) ans = tmp;
        }
        cout << setiosflags(ios::fixed) << setprecision(12) << ans << endl;
    }
	return 0;
}

