#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 25;
const int mod = 1e9 + 7;

LL QuickPow(int k)
{
    LL ans = 1, tmp = 4;
    while (k) {
        if (k & 1) {
            ans *= tmp;
            ans %= mod;
        }
        k >>= 1;
        tmp *= tmp;
        tmp %= mod;
    }
    return ans;
}

int main()
{
    LL n, f[maxn] = {0, 1, 2};
    for (int i = 3; i < maxn; i++) {
        f[i] = f[i - 1] + 1;
        for (int k = 1; k + 2 < i; k++) {
            f[i] = max(f[i], f[i - 2 - k] * (k + 1));
        }
        f[i] %= mod;
    }
    while (cin >> n) {
        if (n < 16) cout << f[n] << endl;
        else {
            int x = (n - 11) % 5;
            x += 11;
            int k = (n - x) / 5;
            LL ans = f[x] * QuickPow(k);
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}
