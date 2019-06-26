#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 150005;
int GCD(int x, int y) {
    return y ? GCD(y, x % y) : x;
}

int main()
{
    int n, a, b, c[maxn];
    set<int> sTmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        set<int> s;
        for (int j = 2; j <= a; j++) {
            if (a % j == 0) {
                s.insert(j);
                while (a % j == 0) a /= j;
            }
        }
        for (int j = 2; j <= b; j++) {
            if (b % j == 0) {
                s.insert(j);
                while (a % j == 0) b /= j;
            }
        }
        if (i != 0) {
            //vector<int> v(maxn);
            //set_intersection(s.begin(), s.end(), sTmp.begin(), sTmp.end(), v.begin());
            set<int> v;
            for (int x : s) {
                for (int y : sTmp) {
                    if (x == y) v.insert(x);
                }
            }

            sTmp.clear();
            for (int elem : v) sTmp.insert(elem);
            s.clear();
            v.clear();
        }
        else {
            sTmp.clear();
            for (int elem : s) sTmp.insert(elem);
        }
    }
    if (sTmp.size() == 0) cout << -1 << endl;
    else cout << *(--sTmp.end()) << endl;
    return 0;
}

