#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    int lenS = S.size(), lenT = T.size();

    int cnt = 0;
    for (int i = 0; i < lenS - lenT; i++) {
        string tmp = S.substr(i, lenT);
        unordered_map<char, char> m;
        for (int i = 0; i < 26; i++) {
            m['a' + i] = '0';
        }
        bool flag = true;
        for (int i = 0; i < lenT; i++) {
            if (m[tmp[i]] != '0') {
                if (m[tmp[i]] != T[i]) {
                    flag = false;
                    break;
                }
            }
            else  m[tmp[i]] = T[i];
        }
        if (flag) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
/*
ababcb
xyx
*/


