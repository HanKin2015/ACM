#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string father;
    bool flag = false, isStart = false;
    for(int i = 0; i < n; i++) {
        char* str;
        string temp = "";
        gets(str);
        for(int i = 0; i < strlen(str); i++) {
            if(str[i] == '"' && !isStart) {
                isStart = true;
            }
            else if(str[i] == '"') {
                if(str[i - 1] == '\\') {
                    temp += '"';
                }
                else {
                    isStart = false;
                    father = temp;
                }
            }
            else if(str[i] == '\\') {
                if(str[i - 1] == '\\') {
                    temp += '\\';
                }
            }
            else temp += str[i];
        }
    }
    return 0;
}
