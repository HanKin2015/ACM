#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 5;
const int maxn = 1e3 + 5;

int main()
{
    int N, seq[maxN], cache[maxn];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> seq[i];
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans, maxHit = -1;
    for (int i = 1; i < maxn; i++) {
        int hit = 0;
        int vis[maxn];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < maxn; i++) cache[i] = -1;

        for (int j = 0; j < N; j++) {
            if (vis[seq[j]]) hit++;   // 命中
            else {
                int tmp = seq[j] % i;
                if (cache[tmp] != -1) {
                    vis[cache[tmp]] = 0;
                }
                vis[seq[j]] = 1;
                cache[tmp] = seq[j];  // 替换原来的缓存
            }
        }
        if (hit > maxHit) {
            maxHit = hit;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}

