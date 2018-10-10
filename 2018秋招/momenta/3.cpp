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

int ans = 0, n, apple[4];
void dfs(int sum)
{
    if (sum > n) return;
    if (sum == n) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        dfs(sum + apple[i]);
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> apple[i];
    dfs(0);
    cout << ans << endl;
	return 0;
}
