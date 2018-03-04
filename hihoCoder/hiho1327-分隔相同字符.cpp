#include <bits/stdc++.h>
using namespace std;

int main()
{
    char S[100005];
    cin >> S;
    int len = strlen(S);
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < len; i++) {
        cnt[S[i] - 'a']++;
    }
    int maxn = *max_element(cnt, cnt + 26);
    if(maxn > (len + 1) / 2) {
        cout << "INVALID" << endl;
        return 0;
    }
    char pre = 'A';
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < 26; j++) {
            char c = 'a' + j;
            if(c == pre || cnt[j] == 0) continue;
            cnt[j]--;
            maxn = *max_element(cnt, cnt + 26);
            if(maxn <= (len - i) / 2) {
                cout << c;
                pre = c;
                break;
            }
            else cnt[j]++;
        }
    }
    cout << endl;
    return 0;
}
