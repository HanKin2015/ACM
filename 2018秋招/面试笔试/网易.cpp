#include <bits/stdc++.h>
#define LL long long
using namespace std;

//emum


LL F(string str, int x)
{
    LL num = 0, tmp = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        switch (str[i]) {
        case 'A':
            num += 10 * tmp;
            break;
        case 'B':
            num += 11 * tmp;
            break;
        case 'C':
            num += 12 * tmp;
            break;
        case 'D':
            num += 13 * tmp;
            break;
        case 'E':
            num += 14 * tmp;
            break;
        case 'F':
            num += 15 * tmp;
            break;
        default:
            num += (str[i] - '0') * tmp;
        }
        tmp *= x;
        if (num < 0) return -1;
    }
    return num;
}

int main()
{
    //string str = "abcd";
    //string s = str.substr(0, 0);
    //cout << s << endl;
    int T; cin >> T;
    while (T--) {
        int x, y;
        string z;
        cin >> x >> y >> z;
        int len = z.size();
        for (int i = 1; i < len; i++) {
            string s1 = z.substr(0, i);
            string s2 = z.substr(i, len);
            LL n1 = F(s1, x);
            LL n2 = F(s2, y);
            if (n1 == n2) {
                cout << n1 << endl;
                break;
            }
        }
    }
    return 0;
}

/*
3
5 2 113221101000101
13 7 1016
4 12 2222248A
*/
