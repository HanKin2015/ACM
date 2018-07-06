#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while(cin >> n >> m) {
        long long ans = (n / (2 * m));
        ans *= m * m;
        cout << ans << endl;
    }
    return 0;
}
