#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    stack<string> S;
    int i = 0;
    string tmp;
    while (i < len) {
        while (i < len && str[i] == '/') i++;

        tmp.clear();
        while (i < len && str[i] != '/') {
            tmp += str[i];
            i++;
        }
        if (tmp == "..") {
            if (!S.empty()) S.pop();
        } else if (tmp == ".")
            continue;
        else if (!tmp.empty()) {
            S.push(tmp);
        }
    }
    if (S.empty()) {
        cout << "/";
        return 0;
    }
    string result = "";
    while (!S.empty()) {
        result = "/" + S.top() + result;
        S.pop();
    }
    cout << result << endl;
    return 0;

}
