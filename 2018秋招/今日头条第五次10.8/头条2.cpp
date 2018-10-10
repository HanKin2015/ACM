#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e5 +5;
LL n, m, x[maxn], y[maxn];
LL num = 0;
LL ans = 0;

void dfs(LL index, LL cnt, LL sum1, LL sum2)
{
    if (cnt > m || sum1 > n) return;
    if (sum2 > ans) ans = sum2;
    if (index >= num) return;
    dfs(index + 1, cnt, sum1, sum2);
    dfs(index + 1, cnt + 1, sum1 + x[index], sum2 + y[index]);
    return;
}

//int a[105], b[105];
//void dfs(int index, int cnt)
//{
//    if (cnt > m) return;
//    if (index >= num) {
//        int sumx = 0, sumy = 0;
//        for (int i = 0; i < cnt; i++) {
//            sumx += a[i];
//            sumy += b[i];
//        }
//        if (sumy == 620) {
//            for (int i = 0; i < cnt; i++) {
//                cout << b[i] << endl;
//            }
//        }
//        if (sumx <= n && sumy > ans) ans = sumy;
//        return;
//    }
//    a[cnt] = x[index];
//    b[cnt] = y[index];
//    dfs(index + 1, cnt);
//    dfs(index + 1, cnt + 1);
//    return;
//}

int main()
{
    cin >> n >> m;
    while (cin >> x[num] >> y[num]) num++;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}

