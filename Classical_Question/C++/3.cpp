#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int t; cin >> t;
    while(t--) {
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;
        int ans = 0;
        int len = str.length();
        for(int i = 0; i < len; i++) {
            if(str[i] == 'u') X--;
            else if(str[i] == 'd') X++;
            else if(str[i] == 'l') Y--;
            else if(str[i] == 'r') Y++;
            if(X >= 1 && X <= N && Y >= 1 && Y <= M) ans++;
            else {
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}