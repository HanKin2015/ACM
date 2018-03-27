#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int cnt = 0;
        while(str[i] == ch && i < str.length()) {
            i++;
            cnt++;
        }
        i--;
        cout << cnt << ch;
    }
    return 0;
}
