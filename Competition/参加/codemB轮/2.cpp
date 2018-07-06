#include <bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return x & (-x);
}

int f(int l, int r)
{
    if(l >= r) return 0;
    if(r - lowbit(r) >= l) return f(l, r - lowbit(r)) + 1;
    return f(l, r - 1) + 1;
}

void display(int n)
{
    int a[32], dex = 0;
    while(n) {
        a[dex++] = n % 2;
        n >>= 1;
    }
    for(int i = dex - 1; i>= 0; i--) cout << a[i];
    return;
}

int main()
{
    cout << lowbit(8) << endl;
    //string n;
    int n;
    while(cin >> n) {
        int max_ans = 0, x, y;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(f(i, j) >= max_ans) {
                    //cout << i << ' ' << j << ' ' << f(i, j) << endl;
                    max_ans = f(i, j);
                    x = i, y = j;
                }
            }
        }
        display(n);
        cout << ' ';
        display(x);
        cout << ' ';
        display(y);
        cout << ' ' << max_ans << ' ';
        display(max_ans);
        cout << endl;
    }
    return 0;
}

