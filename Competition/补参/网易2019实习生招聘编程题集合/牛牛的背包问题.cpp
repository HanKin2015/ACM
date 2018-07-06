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

int n, w, v[maxn], ans = 0;
void dfs(LL sum, int index)
{
    if(sum > w) return;
    if(index == n) {
        ans++;
        return;
    }
    dfs(sum, index + 1);
    dfs(sum + v[index], index + 1);
    return;
}

int main()
{
    LL total = 0;
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> v[i], total += v[i];
    if(total <= w) {
        ans = pow(2, n);   //好气啊，没有做这个判断
        cout << ans << endl;
        return 0;
    }
    sort(v, v + n);
    for(int i = 0; i < n; i++) {
        if(v[i] > w) {
            n = i;
            break;
        }
    }
    dfs(0, 0);
    cout << ans << endl;
	return 0;
}
