#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[10005];
    while(cin >> str) {
        int len = strlen(str);
        for(int i = 0; i < len; i++) {
            for(int j = len - 1; j > 0; j--) {
                if(str[j - 1] == 'B' && (str[j] == 'R' || str[j] == 'G')) swap(str[j], str[j - 1]);
                if(str[j - 1] == 'G' && str[j] == 'R') swap(str[j], str[j - 1]);
            }
        }
        cout << str << endl;
    }
    return 0;
}
