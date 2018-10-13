#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 1005
using namespace std;
int dp[maxn][maxn];
int main()
{
    string s1, s2;
    while(cin >> s1) {
        memset(dp, 0, sizeof(dp));
        s2 = s1;
        int len = s1.size();
        for(int i = 0; i < len; i++) s2[i] = s1[len - 1 - i];
        for(int i = 0; i <= len; i++) {
            for(int j = 0; j <= len; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else if(s1[i - 1] != s2[j - 1]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        //cout << len - dp[len][len] << endl;
        int ans = 1;
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++) {
                cout << dp[i][j] << endl;
                if(dp[i][j] != 0) {
                    ans++;
                }
            }
        }
        cout << ans / 2<< endl;
    }
	return 0;
}
