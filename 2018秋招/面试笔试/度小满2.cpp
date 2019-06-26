#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 +5;

int main()
{
    int n, a[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        long long ans = 0;
        for (int j = 0; j <= i; j++) {
            for (int k = i + 1; k < n; k++) {
                if (a[j] ^ a[k]) ans++;
            }
        }
        if (i == n - 2) printf("%lld", ans);
        else printf("%lld ", ans);
    }
    printf("\n");
    return 0;
}
