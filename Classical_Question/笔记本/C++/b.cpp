#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while(cin >> m >> n) {
        map<string, int> dic;
        string str;
        for(int i = 0; i < m; i++) {
            cin >> str;
            dic[str] = 1;
        }
        for(int i = 0; i < n; i++) {
            cin >> str;
            string temp = "";
            bool flag = false;
            for(int j = 0; j < str.size(); j++) {
                temp += str[j];
                if(dic[temp] == 1) {
                    cout << 1 << endl;
                    flag = true;
                    break;
                }
            }
            if(!flag) cout << -1 << endl;
        }
        cout << endl;
        dic.clear();
    }
    return 0;
}