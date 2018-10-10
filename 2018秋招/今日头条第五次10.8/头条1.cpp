#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e3 +5;
int dp[maxn][maxn * 9];

int main()
{
    int a, b, k;
    while (cin >> a >> b >> k) {
        memset(dp, 0, sizeof(dp));
        dp[1][a] = 1;
        dp[1][b] = 1;
        int maxSum = max(a, b) * k;
        for (int i = 2; i <= k; i++) {
            for (int j = max(a, b); j <= maxSum; j++) {
                dp[i][j] = dp[i - 1][j - a] + dp[i - 1][j - b];
                dp[i][j] %= mod;
            }
        }
        int ans = 0;
        for (int i = min(a, b); i <= maxSum; i++) {
            if (dp[k][i]) {
                int n = i;
                bool flag = true;
                while (n) {
                    if (n % 10 != a && n % 10 != b) flag = false;
                    n /= 10;
                }
                if (flag) {
                    ans = (ans + dp[k][i]) % mod;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
作者：milazo
链接：https://www.nowcoder.com/discuss/124524?toCommentId=2098123
来源：牛客网

#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
#include<fstream>
using namespace std;
const long long MOD=1000000007;

int inv(int a)
{
    return a==1?1:(long long)(MOD-MOD/a)*inv(MOD%a)%MOD;
}
long long  C(long long n,long long  m)
{
    if(m<0)return 0;
    if(n<m)return 0;
    if(m>n-m)m=n-m;
    long long up=1,down=1;
    for(long long  i=0;i<m;i++)
    {
        up=up*(n-i)%MOD;
        down=down*(i+1)%MOD;
    }
    return up*inv(down)%MOD;
}
int main(){
    int a,b,k;     cin>>a>>b>>k;     long long ans =0;
    for(int i=0;i<=k;i++){
        int sum = i * a + (k-i) *b;
        int flag = 0;
        while(sum){
            if(sum%10 == a || sum %10 == b){
            sum/=10;
            continue;
             }
             flag=1;
             break;
             }
             if(flag==0){
             ans = (ans+C(k,i))%MOD;
             }
    }     cout<<ans<<endl;
    return 0;
}
*/
