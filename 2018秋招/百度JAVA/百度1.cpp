#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 +5;

// 12样例过了9个样例
string townName(int size, vector<string> people)
{
    string ans = "";
    if (size == 0) return ans;
    ans = people[0];
    int len = people[0].size();
    for (int i = 1; i < size; i++) {
        len = min(len, (int)people[i].size());
        for (int j = 0; j < len; j++) {
            if (ans[j] != people[i][j]) {
                len = j;
                break;
            }
        }
    }
    ans = ans.substr(0, len);
    //cout << ans << endl;
    return ans;
}

int main()
{
    int n;
    vector<string> people(maxn);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> people[i];
    townName(n, people);
    return 0;
}
/*
4
abchhjk
abchhyu
abchh2
abchhch
*/

