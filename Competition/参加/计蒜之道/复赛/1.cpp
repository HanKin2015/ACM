#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
};

bool cmp(node x, node y) {
    return (y.a - 1) * x.b > (x.a - 1) * y.b;
}

int main()
{

    int T; cin >> T;
    while(T--) {
        node eps[10005];
        int n, x, temp;
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            eps[i].a = temp;
        }
        for(int i = 0; i < n; i++) {
            cin >> temp;
            eps[i].b = temp;
        }
        sort(eps, eps + n, cmp);
        long long ans = x;
        for(int i = 0; i < n; i++) {
            ans = eps[i].a * ans + eps[i].b;
            ans %= 1000;
        }
        cout << ans % 10 << endl;
    }
    return 0;
}

