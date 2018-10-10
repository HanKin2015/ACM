/*
*01背包问题
*有一个背包，容量为c，这里有n个物品，每个物品有体积v和价值w，问装下的最大价值是多少？
10 5
1 6
3 4
5 3
7 5
8 2

13
*/
#include <bits/stdc++.h>
using namespace std;

//暴力求解，列举所有装法
int c, n, v[1005], w[1005]; 
int ans = 0;
void dfs(int volume, int value, int cnt)
{
    if(volume > c) return;
    if(cnt == n) {  //cnt无法作为下标的时候
        if(value > ans) ans = value;
        return;
    }
    dfs(volume, value, cnt + 1);
    dfs(volume + v[cnt], value + w[cnt], cnt + 1);
    return;
}

int main()
{
    cin >> c >> n;
    for(int i = 0; i < n; i++) cin >> v[i] >> w[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}