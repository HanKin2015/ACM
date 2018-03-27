/*
*有一个大小为N*M的园子，雨后积起了水。八连通的积水被认为是连接在一起的。请求出院子里共有多少水洼？

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

3
*/
#include <iostream>
#define rep(i, l, r) for(int i = l; i < r; i++)
using namespace std;

int N, M;
char mat[105][105];
void dfs(int x, int y)
{
    mat[x][y] = '.';
    rep(i, -1, 2) {
        rep(j, -1, 2) {
            int dx = x + i, dy = y + j;
            if(0 <= dx && dx < N && 0 <= dy && dy < M && mat[dx][dy] == 'W') {
                dfs(dx, dy);
            }
        }
    }
    return;
}

int main()
{
    cin >> N >> M;
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    rep(i, 0, N) {
        rep(j, 0, M) {
            if(mat[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout <<  ans << endl;
    return 0;
}

/*
#include<cstdio>
#include<cstring>
const int MAXN=100+10;
char map[MAXN][MAXN];
int n,m;
void dfs(int x,int y)
{
    if(map[x][y]=='.')
        return ;

     map[x][y]='.';
     dfs(x+1,y+1);
     dfs(x,y+1);
     dfs(x-1,y+1);
     dfs(x-1,y);
     dfs(x-1,y-1);
     dfs(x,y-1);
     dfs(x+1,y-1);
     dfs(x+1,y);
}

int main()
{
    while(~scanf(%d%d,&n,&m)){
        for(int i=1;i<=n;i++)
            scanf(%s,map[i]+1);

        for(int i=0;i<=n+1;i++)
            map[i][0]=map[i][m+1]='.';
        for(int i=0;i<=m+1;i++)
            map[0][i]=map[n+1][i]='.';

        int ans=0;
        for(int i=0;i<=n+1;i++) {
            for(int j=0;j<=m+1;j++) {
                if(map[i][j]=='W') {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
*/
