#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    int A[105], sum = 0, dp[500005];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if(sum < X) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = sum; j >= X + A[i]; j--) {
            dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
        }
    }
    cout << sum - dp[sum] << endl;
    return 0;
}

