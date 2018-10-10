#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n1, n2, m, a[105], b[105];
int ans = 0;
void dfs(int dex, int sum)
{
    if(sum > m || dex > n1 + n2) return;
    if(dex == n1 + n2) {
        if(sum == m) ans++;
        ans %= mod;
        return;
    }
    if(dex < n1) {
        dfs(dex + 1, sum);
        dfs(dex, sum + a[dex]);
    }
    else {
        dfs(dex + 1, sum);
        dfs(dex + 1, sum + b[dex - n1]);
    }
    return;
}

int main()
{
    //cout << mod << endl;
    cin >> n1 >> n2 >> m;
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}