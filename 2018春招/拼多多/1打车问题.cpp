#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, p;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p;
        if(p == 1) cnt1++;
        else if(p == 2) cnt2++;
        else if(p == 3) cnt3++;
        else cnt4++;
    }
    //cout << cnt1 << cnt2 << cnt3 << cnt4 << endl;
    int ans = cnt4 + cnt2 / 2;
    cnt2 %= 2;
    if(cnt1 > cnt3) {
        ans += cnt3;
        cnt1 -= cnt3;
        cnt3 = 0;
    }
    else {
        ans += cnt1;
        cnt3 -= cnt1;
        cnt1 = 0;
    }
    if(cnt3 != 0) ans += cnt3;
    if(cnt2 == 1) cnt1 += 2;
    if(cnt1 != 0) ans = ans + (cnt1 + 3) / 4;
    cout <<  ans << endl;
    return 0;
}
