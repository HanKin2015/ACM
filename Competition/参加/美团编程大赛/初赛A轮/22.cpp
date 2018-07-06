#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    n++;
    int ans = k * n;
    int x[1005], y[1005];
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < m; i++) {
        int cnt = n / y[i], temp = n % y[i];
        if(temp != 0) {
            int sum = (cnt + 1) * x[i];
            if(sum < ans) ans = sum;
            sum = cnt * x[i] + k * temp;
            if(sum < ans) ans = sum;
            for(int j = 0; j < m; j++) {
                if(y[j] >= temp) sum = cnt * x[i] + x[j];
                else sum = cnt * x[i] + temp / y[j] * x[j] + (temp % y[j]) * k;
                if(sum < ans) ans = sum;
            }
        }
        else {
            int sum = cnt * x[i];
            if(sum < ans) ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
22 3 5
10 5
14 7
22 11

46
*/
