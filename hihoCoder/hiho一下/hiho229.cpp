#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K;
    string str;
    cin >> K;
    cin >> str;
    int len = str.size();
    static int cnt[100005][26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j];
        int letter = str[i - 1] - 'a';
        cnt[i][letter] = cnt[i - 1][letter] + 1;
    }
    int ans = 0;
    for (int i = 1, j = 1; i <= len && j <= len;) {
        //cout << i << ' ' << j << endl;
        bool flag = false;
        for (int k = 0; k < 26; k++) {
            int num = cnt[j][k] - cnt[i - 1][k];
            int tmp = j - i + 1 - num;
            if (tmp <= K && cnt[len][k] - num >= tmp) {
                flag = true;
                break;
            }
        }
        if (flag) {
            ans = max(ans, j - i + 1);
            j++;
        }
        else i++;
    }
    cout << ans << endl;
    return 0;
}
