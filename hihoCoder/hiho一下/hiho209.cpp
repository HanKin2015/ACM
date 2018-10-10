#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int k = log2(n);
    int ret1 = n - int(pow(2, k));
    int ret2 = int(pow(2, k + 1)) - n;
    return ret1 > ret2 ? ret2 : ret1;
}

int main()
{
    //cout << log(8) << endl;  //Ä¬ÈÏÒÔeÎªµ×
    //cout << log2(8) << endl;
    //cout << fun(7) << endl;
    int N;
    while(cin >> N) {
        int ans = 0;
        while(N) {
            N = fun(N);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
