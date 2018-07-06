#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0; cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str[0] == str[3] && str[1] == str[4]) ans++;
        else if(str[0] == str[1] && str[3] == str[4]) ans++;
        else if(str[0] == str[4] && str[1] == str[3]) ans++;
        str = "";
    }
    cout << ans << endl;
    return 0;
}
