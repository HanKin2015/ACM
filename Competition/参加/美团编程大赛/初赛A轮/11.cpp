#include <bits/stdc++.h>
using namespace std;

int vis[1005][1005], cnt[1005][1005];
int main()
{
    int n, x, y;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(vis[i][j]) cnt[i][j] = 1;
            //else cnt[i][j] = 0;
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
        }
    }
    int m, a1, b1, a2, b2;
    cin >> m;
    while(m--) {
        cin >> a1 >> b1 >> a2 >> b2;
        int ans = cnt[a2][b2] + cnt[a1 - 1][b1 - 1] - cnt[a1 - 1][b2] - cnt[a2][b1 - 1];
        cout << ans << endl;
    }
    return 0;
}
