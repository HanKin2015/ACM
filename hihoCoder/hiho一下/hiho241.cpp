#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp[10][10];
    memset(dp, 1, sizeof(dp));  // ֻ�����0��-1
    cout << dp[1][1] << endl;

    int a = -2, b = -2;
    cout << (!a) << endl;
    cout << (~b) << endl;  //����"��"�����������ֻ��0��1��������"~"����󣬽���ж��֣�ȡ���ڲ�������

    int T;
    cin >> T;
    while (T--) {
        int n, k, A[200005];
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> A[i];

    }
    return 0;
}
