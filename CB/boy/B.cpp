#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans[10005], cnt = 1;
    for(int i = 19; i < 10900000;  i++) {
        int n = i, sum = 0;
        while(n) {
            sum += (n % 10);
            n /= 10;
        }
        if(sum == 10) ans[cnt++] = i;
    }
    int k;
    cin >> k;
    cout << ans[k] << endl;
    return 0;
}

