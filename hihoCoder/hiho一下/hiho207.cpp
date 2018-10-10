#include <bits/stdc++.h>
using namespace std;

int ans_hour = 0, ans_minute = 0;

void cmp(int h, int m)
{
    if(h == ans_hour) {
        if(m > ans_minute) {
            ans_minute = m;
        }
    }
    else if(h > ans_hour) {
        ans_hour = h;
        ans_minute = m;
    }
    return;
}

bool judge(int h, int m)
{
    if(h >= 0 && h <= 23 && m >= 0 && m <= 59) return true;
    return false;
}

int main()
{
    int a[4];
    for(int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);
    bool flag = false;
    do {
        int h = a[0] * 10 + a[1];
        int m = a[2] * 10 + a[3];
        if(judge(h, m)) {
            cmp(h, m);
            flag = true;
        }
    } while(next_permutation(a, a + 4));
    if(!flag) cout << "NOT POSSIBLE" << endl;
    else {
        if(ans_hour < 10) cout << 0;
        cout << ans_hour << ':';
        if(ans_minute < 10) cout << 0;
        cout << ans_minute << endl;
    }
    return 0;
}

