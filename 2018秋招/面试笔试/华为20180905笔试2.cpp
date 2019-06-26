#include <bits/stdc++.h>
using namespace std;

struct ST {
    string str;
    int cnt;
};

const int maxn = 1e4 + 5;

bool cmp(ST a, ST b) {
    if (a.cnt == b.cnt) return a.str < b.str;
    return a.cnt < b.cnt;
}

int main()
{
    ST st[maxn];
    int pos = 0;

    string input;
    cin >> input;
    int len = input.size();
    string str = "";
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            cnt = cnt * 10 + input[i] - '0';
            if (i + 1 < len) {
                if (input[i + 1] < '0' || input[i + 1] > '9') {
                    st[pos].str = str;
                    st[pos++].cnt = cnt;
                    str = "";
                    cnt = 0;
                }
            }
            else {
                st[pos].str = str;
                st[pos++].cnt = cnt;
            }
            continue;
        }
        str += input[i];
    }

    sort(st, st + pos, cmp);
    for (int i = 0; i < pos; i++) {
        for (int j = 0; j < st[i].cnt; j++) {
            cout << st[i].str;
        }
    }
    cout << endl;
    return 0;
}
/*
a11b2bac3bad3abcd2
*/
