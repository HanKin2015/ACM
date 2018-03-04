#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[205];
    cin >> str;
    int len = strlen(str);
    bool vis[26];
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == 'J') str[i] = 'I';
        if(!vis[str[i] - 'A']) {
            cout << str[i];
            vis[str[i] - 'A'] = 1;
            cnt++;
            if(cnt == 5) cout << endl, cnt = 0;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(!vis[i] && i != 'J' - 'A') {
            char ch = 'A' + i;
            cout << ch;
            cnt++;
            if(cnt == 5) cout << endl, cnt = 0;
        }
    }
    return 0;
}
