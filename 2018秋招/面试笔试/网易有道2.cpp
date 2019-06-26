#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e6 + 5;

int main()
{
    LL n, k;
    cin >> n >> k;
    string card;
    cin >> card;
    LL cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[card[i] - 'A']++;
    sort(cnt, cnt + 26);
    LL ans = 0;
    for (int i = 25; i >= 0; i++) {
        if (cnt[i] <= k) {
            ans += cnt[i] * cnt[i];
            k -= cnt[i];
        }
        else {
            ans += k * k;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

