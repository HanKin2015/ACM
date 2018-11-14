#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    constexpr int mod = 1e9 + 7;
    cin >> T;
    int res[100005] = {1, 1, 2, 5};
    for (int i = 4; i < 100005; i++) {
        res[i] = res[i - 1] * 2 + res[i - 3];
        res[i] %= mod;
    }
    while (T--) {
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
