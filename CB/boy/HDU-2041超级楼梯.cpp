#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int ans, N, M;

void dfs(int current) {
    if(current > M) return;
    if(current == M) {
        ans++;
        return;
    }
    dfs(current + 1);
    dfs(current + 2);
        return;
}

int digui(int m) {
 	if(m == 1) return 1;
 	if(m == 2) return 1;
 	return digui(m-1) + digui(m-2);
}

int main()
{
    cin >> N;
    while(N--) {
        cin >> M;
        if(M == 1) {
            cout << 0 << endl;
            continue;
        }
        ans = 0;
        dfs(1);
        cout << ans << endl;
        cout << digui(M) << endl;
        int dp[105];
        memset(dp, 0, sizeof(dp));
        //�����е㲻�Ͻ�����M==1ʱ����Ӧ����0��Ϊ�˼�㣬ǰ�����⴦��
        dp[1] = 1, dp[2] = 1;
        for(int i = 3; i < 45; i++) dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[M] << endl;
        vector<int> v;
        *min_element(v.begin(), v.end());
    }
    return 0;
}�õ�STL��stable_partition �������
