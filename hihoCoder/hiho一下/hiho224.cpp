#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, K, A, cnt[maxn];
        memset(cnt, 0, sizeof(cnt));
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> A;
            cnt[A]++;
        }
        bool flag = true;
        if (N % K != 0) flag = false;
        for (int i = 1; i < maxn && flag; i++) {
            while (cnt[i] != 0) {
                cnt[i]--;
                for (int j = i + 1; j < i + K; j++) {
                    if (cnt[j] == 0) {
                        flag = false;
                        break;
                    }
                    cnt[j]--;
                }
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
