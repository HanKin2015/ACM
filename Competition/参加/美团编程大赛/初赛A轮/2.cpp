#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a[100005], b[100005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int a_tex = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(b[i] != 0) {
            int a_tag = i;  // 先寻找右边的资源
            bool flag = true, vis = false;
            while(flag) {
                while(a[a_tag] == 0 && a_tag < n - 1) a_tag++;
                if(a[a_tag] != 0) {
                    if(a[a_tag] > b[i]) {
                        a[a_tag] -= b[i];
                        if(i <= a_tag) ans += (a_tag - i) * b[i];
                        else ans += (a_tag * 2 + i - a_tag) * b[i];
                        flag = false;
                        b[i] = 0;
                    }
                    else if(a[a_tag] == b[i]) {
                        if(i <= a_tag) ans += (a_tag - i) * b[i];
                        else ans += (a_tag * 2 + i - a_tag) * b[i];
                        a[a_tag] = 0;
                        a_tag++;
                        b[i] = 0;
                        flag = false;
                    }
                    else {
                        if(i <= a_tag) ans += (a_tag - i) * a[a_tag];
                        else ans += (a_tag * 2 + i - a_tag) * a[a_tag];
                        b[i] -= a[a_tag];
                        a[a_tag] = 0;
                        a_tag++;
                    }
                }
                if(a_tag == n - 1 && flag) a_tag = a_tex, vis = true;
            }
            if(vis) a_tex = a_tag;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

/*
5
0 4 0 2 0
2 0 2 0 2
14

5
0 0 5 2 0
2 0 0 0 5
36

5
0 0 1 1 0
1 0 0 0 1
9
*/
