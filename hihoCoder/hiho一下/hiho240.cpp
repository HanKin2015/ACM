#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int mod = 1e9 + 7;
    long long N, f[100005] = {1, 2, 4, 7}, g[100005] = {1, 3, 8, 19};
    for (int i = 4; i < 100005; i++) {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
        g[i] = (f[i] + g[i - 1] + g[i - 2] + g[i - 3]) % mod;
    }
    cin >> N;
    cout << g[N] << endl;
    return 0;
}
