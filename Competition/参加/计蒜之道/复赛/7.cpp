#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
typedef long long LL;

void exgcd(LL a, LL b, LL &x, LL &y)
{
    if(!b) {
        y = 0, x = 1;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        int cnt[30];
        memset(cnt, 0, sizeof(cnt));
        cin >> s;
        cin >> t;
        for(int i = 0; i < s.size(); i++) {
            cnt[int(s[i] - 'a')]++;
        }
        bool flag = true;
        for(int i = 0; i < t.size(); i++) {
            if(cnt[int(t[i] - 'a')]) cnt[int(t[i] - 'a')]--;
            else {
                flag = false;
                break;
            }
        }
        if(!flag) cout << 0 << endl;
        else {
            int temp = s.size() - t.size();
            long long ans = 1;
            for(int i = 1; i <= temp; i++) {
                ans *= i;
                ans %= mod;
            }
            long long fenmu = 1;
            for(int i = 0; i < 28; i++) {
                if(cnt[i]) {
                    for(int j = 1; j <= cnt[i]; j++) {
                        fenmu *= j;
                        fenmu %= mod;
                    }
                }
            }
            ans = ans * (temp + 1) % mod;
            LL x, y;
            exgcd(fenmu, mod, x, y);
            x = (x % mod + mod) % mod;
            ans = ans * x % mod;
            cout << ans << endl;
        }
    }
    return 0;
}


