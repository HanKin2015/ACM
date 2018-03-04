#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define LL long long
using namespace std;

int main()
{
    char S[505];
    cin >> S;
    int len = strlen(S);
    int dp[505][505];
    memset(dp, 0, sizeof(dp));
    for(int i = len - 1; i >= 0; i--) {
        for(int j = i + 1; j < len; j++) {
            if(S[i] == S[j]) dp[i][j] = dp[i + 1][j - 1];
            else {
                dp[i][j] = min(dp[i][j - 1], min(dp[i + 1][j], dp[i + 1][j - 1])) + 1;
            }
        }
    }
    cout << dp[0][len - 1] << endl;
    return 0;
}

