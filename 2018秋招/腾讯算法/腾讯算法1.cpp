#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    LL X, Y;
    cin >> X >> Y;
    LL sum = X + Y;
    LL N = sqrt(2 * sum);
    if(N * (N + 1) != 2 * sum) {  // 不满足条件
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    for (LL i = N; ;i--) {  // 一定有答案,1-10^6和约为10^12,即O(log(X))
        X -= i;
        cnt++;
        if (X <= i - 1) {
            cnt++;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}
