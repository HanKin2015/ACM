#include<bits/stdc++.h>
using namespace std;
int x[10], y[10], a[7][2];
bool vis[10], f = 0;
void dfs(int pos)
{
    if(f == 1)	return;
    if(pos == 7) {
        if(a[1][0] == a[2][1] && a[2][1] == a[5][0])
            if(a[1][1] == a[3][0] && a[3][0] == a[5][1])
                if(a[2][0] == a[4][1])
                    if(a[3][1] == a[6][0])	f = 1;
        return;
    }
    for(int i = 1; i <= 6; i++) {
        if(vis[i])	continue;
        vis[i] = 1;
        a[pos][0] = x[i], a[pos][1] = y[i];
        dfs(pos + 1);
        a[pos][0] = y[i], a[pos][1] = x[i];
        dfs(pos + 1);
        vis[i] = 0;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        f = 0;
        for(int i = 1; i <= 6; i++)	vis[i] = 0;
        for(int i = 1; i <= 6; i++)	cin >> x[i] >> y[i];
        dfs(1);
        if(f)	puts("YES");
        else puts("NO");
    }
}
