#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int len = S.size(), cnt = 0;
        bool flag = true;
        if (len >= 3) {
            for (int i = 0; i < len - 2; i++) {
                if (S[i] == 'L' && S[i + 1] == 'L' && S[i + 2] == 'L') {
                    flag = false;
                    break;
                }
            }
        }
        for (int i = 0; i < len; i++) {
            if (S[i] == 'A') cnt++;
        }
        if (!flag || cnt > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
