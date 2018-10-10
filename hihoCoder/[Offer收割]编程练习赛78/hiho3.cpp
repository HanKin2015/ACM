#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int main()
{
    int N;
    while (cin >> N) {
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        int a[maxn], cnt = 0;
        for (int i = 9; i > 1; i--) {
            while (N % i == 0) {
                N /= i;
                a[cnt++] = i;
            }
        }
        if (N != 1) cout << -1;
        else {
            for (int i = cnt - 1; i >= 0; i--) cout << a[i];
        }
        cout << endl;
    }
    return 0;
}

