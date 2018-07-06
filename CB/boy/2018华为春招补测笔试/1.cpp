#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    set<char> A;
    string str;
    while(cin >> str) {
        int i = 0;
        for(; i < str.size(); i++) {
            if(str[i] == ';') break;
            A.insert(str[i]);
        }
        bool flag = true;
        for(int j = i + 1; j < str.size(); j++) {
            auto ret = find(A.begin(), A.end(), str[j]);
            if(ret == A.end()) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
