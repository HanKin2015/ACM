#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int main()
{
    int n, m, price[maxn], X[maxn], Y[maxn];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < m; i++) cin >> X[i] >> Y[i];
    sort(price, price + n);
    int ans = 0;
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        int maxY = 0, dex = 0;
        for (int j = 0; j < m; j++) {
            if (!vis[j] && price[i] >= X[j]) {
                if (Y[j] > maxY) {
                    maxY = Y[j];
                    dex = j;
                }
            }
        }
        if (maxY) vis[dex] = 1;
        ans += price[i] - maxY;
    }
    cout << ans << endl;
    return 0;
}


