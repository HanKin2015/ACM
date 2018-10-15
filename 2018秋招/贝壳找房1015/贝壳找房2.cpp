#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
typedef long long LL;

LL compute(int pos, string str, int n)
{
    LL len = str.size(), res = 0;
    for (int i = pos; i < len; i++) {
        if (str[i] >= 'A') res = res * n + str[i] - 'A' + 10;
        else res = res * n + str[i] - '0';
    }
    return res;
}

LL str2dec(string str)
{
    int len = str.size();
    if (len == 1) return str[0] - '0';
    if (len == 2) {
        if (str[0] == '0') return str[1] - '0';
        return (str[0] - '0') * 10 + str[1] - '0';
    }
    if (str[0] == '0' && str[1] == 'x') {
        return compute(2, str, 16);
    }
    else if (str[0] == '0') {
        return compute(1, str, 8);
    }
    return compute(0, str, 10);
}

int main()
{
    LL ans = 0;
    string str;
    cin >> str;
    int len = str.size();
    string s = "";
    int pre = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '+') {
            LL tmp = str2dec(s);
            //cout << tmp << endl;
            s = "";
            if (!pre) ans += tmp;
            else ans -= tmp;
            pre = 0;
        }
        else if (str[i] == '-') {
            LL tmp = str2dec(s);
            //cout << tmp << endl;
            s = "";
            if (!pre) ans += tmp;
            else ans -= tmp;
            pre = 1;
        }
        else s += str[i];
    }
    LL tmp = str2dec(s);
    //cout << tmp << endl;
    if (!pre) ans += tmp;
    else ans -= tmp;
    cout << ans << endl;
    return 0;
}

