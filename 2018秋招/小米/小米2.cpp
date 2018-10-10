#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int main()
{
    long long n;
    while (cin >> n) {
        int ans[maxn] = {1};
        for(int i = 2; i <= n; i++) {
            int c = 0;
            for(int j = 0; j < maxn; j++) {
                int tmp = ans[j] * i + c;
                ans[j] = tmp % 10;
                c = tmp / 10;
            }
        }
        bool flag = false;
        for(int j = maxn - 1; j >= 0; j--) {
            if (flag) cout << ans[j];
            else if(ans[j] != 0) {
                flag = true;
                cout << ans[j];
            }
        }
        cout << endl;
    }
    return 0;
}

