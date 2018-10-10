#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[100005], b[100005];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int l, r;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] != b[i]) {
            r = i;
            break;
        }
    }
    int ans = r - l + 1;
    cout << ans << endl;
    return 0;
}
