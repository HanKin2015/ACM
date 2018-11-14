#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    const int maxn = 1e5 + 5;
    pair<int, int> ans[maxn];
    int len = str.size(), dex = 0;
    stack<int> S;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') S.push(i + 1);
        else {
            int tmp = S.top();
            S.pop();
            ans[dex].first = tmp;
            ans[dex++].second = i + 1;
        }
    }
    sort(ans, ans + dex);
    for (int i = 0; i < dex; i++) cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
