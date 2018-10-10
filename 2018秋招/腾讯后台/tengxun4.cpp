#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;
        bool flag = false;
        for (int i = 1; i <= 100; i++) {
            int tmp = A * i;
            if (tmp % B == C) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
