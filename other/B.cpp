#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int V;
        cin >> V;
        int sum = 0, tmp_V = V;
        while (tmp_V) {
            sum += tmp_V % 10;
            tmp_V /= 10;
        }
        int maxn = sqrt(V);
        set<int> s;
        for (int i = 1; i <= maxn; i++) {
            if (V % i == 0) {
                if (sum % i == 0) s.insert(i);
                if (sum % (V / i) == 0) s.insert(V / i);
            }
        }
        int cnt = s.size();
        cout << cnt << endl;
        for (int i : s) {
            cout << i;
            cnt--;
            if (cnt > 0) cout << ' ';
            else cout << endl;
        } 
    }
    return 0;
}