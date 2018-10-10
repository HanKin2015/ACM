#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
bool isPrime(LL n)
{
    set<int> s;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            s.insert(i);
            n /= i;
        }
    }
    if (s.size() == 1) return true;
    return false;
}

const int maxn = 1e6 + 5;
LL n, tmp = 1, ans[maxn];

int main()
{
    bool flag = false;
    while (cin >> n) {
        for (int i = n; i > 0; i--) {
            if (isPrime(i)) {
                cout << i * 2 << endl;
                break;
            }
        }
    }
    return 0;
}

