#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int cnt[maxn][26];

int main()
{
    int T; 
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":" << endl;
        int n, q;
        cin >> n >> q;
        char A[maxn];
        //cin >> A;
        for (int j = 0; j < n; j++) scanf("%c", &A[j]);

        memset(cnt, 0, sizeof(cnt));
        cnt[0][A[0] - 'A'] = 1;
        for (int j = 1; j < strlen(A); j++) {
            int character = A[j] - 'A';
            for (int k = 0; k < 26; k++) {
                if (k == character) cnt[j][k] = cnt[j - 1][k] + 1;
                else cnt[j][k] = cnt[j - 1][k]; 
            }
        }

        int l, r;
        while (q--) {
            //cin >> l >> r;
            scanf("%d%d", &l, &r);
            for (int j = 0; j < 26; j++) {
                int ans = cnt[r - 1][j] - cnt[l - 2][j];
                if (ans != 0) {
                    //cout << ans << endl;
                    printf("%d\n", ans);
                    break;
                }
            }
        }
    }
    return 0;
}