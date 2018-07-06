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
    int n, k, a[maxn];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k > n) cout << -1 << endl;
    else {
        sort(a, a + n);
        if(k == 0) {
            if(a[0] == 1) cout << -1 << endl;
            else cout << 1 << endl;
        }
        else {
            if(k < n && a[k] == a[k - 1]) cout << -1 << endl;
            else cout << a[k - 1] << endl;
        }
    }
    return 0;
}
