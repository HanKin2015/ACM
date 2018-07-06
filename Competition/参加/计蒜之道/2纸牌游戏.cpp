#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100005];
    while(cin >> n) {
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        long long niuniu = 0, yangyang = 0;
        for(int i = n - 1; i >= 0; i--) {
            niuniu += a[i];
            i--;
            if(i >= 0) yangyang += a[i];
        }
        long long ans = niuniu - yangyang;
        cout << ans << endl;
    }
    return 0;
}
