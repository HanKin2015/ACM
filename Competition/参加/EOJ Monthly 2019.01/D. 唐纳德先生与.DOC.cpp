#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int maxn = 1e5 + 5;
using LL = long long;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == str[i + 1]) cout << 'C';
            else cout << 'D';
        }
        cout << endl;
    }
	return 0;
}

