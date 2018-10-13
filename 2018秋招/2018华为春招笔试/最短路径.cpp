/*
最短
*/
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int n,m;
int dp[maxn][maxn];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main(){
    int a,b,c;
    while(cin>>n>>m,n||m){
        memset(dp,inf,sizeof(dp));
        for (int i = 1; i <= n; ++i){
            dp[i][i] = 0;       //不是必要
        }
        for (int i = 1; i <= m; ++i){
            cin>>a>>b>>c;
            dp[a][b] = dp[b][a] = c;
        }
        floyd();
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
