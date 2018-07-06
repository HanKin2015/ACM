#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int k, n, m, C[1005][1005];
int main()
{

    for(int i = 1; i < 1005; i++) {
        C[i][i] = C[i][0] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= mod;
        }

    }
    cin >> k;
    while(k--) {
        cin >> n >> m;
        if(m > n) cout << 0 << endl;
        else cout << C[n][m] % mod << endl;
    }
    return 0;
}
