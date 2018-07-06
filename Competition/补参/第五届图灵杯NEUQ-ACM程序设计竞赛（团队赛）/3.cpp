#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10005
using namespace std;

int main()
{
    int N, a[maxn], vis[maxn];
    memset(vis, 0, sizeof(vis));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(vis[a[i]]) a[i] = 0, cnt++;
        else vis[a[i]] = 1;
    }
    cout << N - cnt << endl;
    cnt = N - cnt;
    for(int i = 0; i < N; i++) {
        if(a[i]) {
            cout << a[i];
            cnt--;
            if(cnt) cout << ' ';
            else cout << endl;
        }
    }
    return 0;
}
