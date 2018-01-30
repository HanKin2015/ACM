#include <iostream>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    long long ans[100005] = {0, 1, 2, 5, 11};
    for(int i = 5; i < 100005; i++) {
        ans[i] = (2 * ans[i - 1] % mod + ans[i - 1])% mod - ans[i - 2] - (2 * ans[i - 3])% mod;
        ans[i] = ans[i] % mod;
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
