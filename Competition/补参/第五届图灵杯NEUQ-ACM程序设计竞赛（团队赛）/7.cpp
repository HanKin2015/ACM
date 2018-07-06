#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 300005
using namespace std;

int main()
{
    int n, k, a[maxn], b[maxn];
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i - 1] = a[i];
    }
    sort(b, b + n);
    map<int, int> m;
    m[b[0]] = 0;
    for(int i = 1; i < n; i++) {
        if(b[i] != b[i - 1]) m[b[i]] = i;
        else m[b[i]] = m[b[i - 1]];
    }
    int cnt[maxn];
    memset(cnt, 0, sizeof(cnt));
    int x, y;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        if(a[x] > a[y]) cnt[x]++;
        if(a[x] < a[y]) cnt[y]++;
    }
    for(int i = 1; i <= n; i++) {
        cout << m[a[i]] - cnt[i] << ' ';
        //if(i < n) cout << ' ';
        //else cout << endl;
    }
    cout << endl;
    return 0;
}
