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
int dp[maxn][maxn], cnt = 0;

void dfs(string str, int dex, char target[55], int tar)
{
    if(dex == str.size()) {
        bool flag = true;
        for(int i = 0; i < tar; i++) {
            if(target[i] != target[tar - i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag && tar) cnt++;
        return;
    }
    target[tar] = str[dex];
    dfs(str, dex + 1, target, tar + 1);
    dfs(str, dex + 1, target, tar);
    return;
}

int main()
{
    int nn = (5&1);
    cout << nn << endl;
    string str;
    while(cin >> str) {
        int len = str.size();
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                dp[i][j] = 1;
            }
        }
        for(int l = 0; l < len - 1; l++) {
            for(int r = len - 1; r > 0; r--) {
                dp[l][r] += dp[l + 1][r] + dp[l][r - 1];
                if(str[l] == str[r]) dp[l][r] = dp[l + 1][r - 1] + 1;
                else dp[l][r] -= dp[l + 1][r - 1];
            }
        }
        cout << dp[0][len - 1] << endl;
        cnt = 0;
        char target[55];
        dfs(str, 0, target, 0);
        cout << cnt << endl;
    }
	return 0;
}
