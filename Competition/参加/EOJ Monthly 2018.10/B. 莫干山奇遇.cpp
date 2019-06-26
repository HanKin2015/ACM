#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL n, a[200005];
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        LL ans = n;
        int p = *max_element(a, a + n) + 1;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) {
                ans += p - a[i - 1] - 1 + a[i];
            }
            else ans += a[i] - a[i - 1] - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL n, a[200005];
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        LL maxn = *max_element(a, a + n);
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) cnt++;
        }
        LL ans = (maxn + 1) * cnt + a[n - 1] + 1;
        if (cnt == 0) {
            ans = a[n - 1] - a[0] + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
*/

/*
8
5 6 7 8 5 6 7 8  ºÃ²Ë°¡
13

4
5 6 7 8
4
*/

