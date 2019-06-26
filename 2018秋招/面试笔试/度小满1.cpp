#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 +5;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (a == 1) {
            cout << "A&B" << endl;
            continue;
        }
        // log(x)/log(y)±íÊ¾log(y)(x)
        int tmp = log(n) / log(a);
        if ((tmp - b) & 1) cout << 'B' << endl;
        else cout << 'A' << endl;
    }
    return 0;
}

