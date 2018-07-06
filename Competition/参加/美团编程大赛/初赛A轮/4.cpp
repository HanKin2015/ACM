#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a[100005], b[100005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] >= a[i]) {
            b[i] -= a[i];
            a[i] = 0;
        }
    }
    int a_left = 0, b_right = n - 1;
    long long ans = 0;
    for(int i = 0; i <= b_right; i++) {
        while(b[i] != 0) {
            while(a[a_left] == 0 && a_left < n - 1) a_left++;
            if(a_left < i) {
                while(a[a_left] != 0) {     // a在左边的全部要用完
                    while(b[b_right] == 0 && b_right > 0) b_right--;
                    if(a[a_left] < b[b_right]) {
                        ans += (a_left * 2 + b_right - a_left) * a[a_left];
                        b[b_right] -= a[a_left];
                        a[a_left] = 0;
                    }
                    else {
                        ans += (a_left * 2 + b_right - a_left) * b[b_right];
                        a[a_left] -= b[b_right];
                        b[b_right] = 0;
                    }
                }
            }
            else {
                if(a[a_left] < b[i]) {
                    ans += (a_left - i) * a[a_left];
                    b[i] -= a[a_left];
                    a[a_left] = 0;
                }
                else {
                    ans += (a_left - i) * b[i];
                    a[a_left] -= b[i];
                    b[i] = 0;
                }
            }
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

5
0 0 5 0 0
1 1 1 1 1
14

4
1 0 0 4
1 4 0 0
8

4
1 4 0 0
1 0 0 4
8

5
0 3 0 2 0
2 0 2 0 1

5
1 2 3 4 5
5 4 3 2 1
20

5
5 4 3 2 1
1 2 3 4 5

3
3 2 1
1 2 3

*/
