#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int main()
{
    char str[maxn];
    //gets(str);
    cin.getline(str, maxn);
    int len = strlen(str);
    map<string, int> cnt;
    string s = "";
    char illegal[8] = {' ', '!', '-', '?', ',', ':', ';', '.'};
    int maxCnt = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = tolower(str[i]);
        bool flag = false;
        for (int j = 0; j < 8; j++) {   // 当有多个的时候就会出错，所以30%
            if (str[i] == illegal[j] || str[i] == ' ') {
                cnt[s]++;
                if (cnt[s] > maxCnt) maxCnt = cnt[s];
                s = "";
                flag = true;
                break;
            }
        }
        if (flag) continue;
        s += str[i];
    }
    if (str[len - 1] >= 'a' && str[len - 1] <= 'z') {
        cnt[s]++;
        if (cnt[s] > maxCnt) maxCnt = cnt[s];
    }
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second == maxCnt) cout << it->first << ' ';
    }
    cout << endl;
    return 0;
}
