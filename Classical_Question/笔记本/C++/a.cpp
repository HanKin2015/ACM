#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
using namespace std;

int main()
{
    char str[100005];
    int ans = 0;
    while(gets(str)) {
        if(strlen(str) <= 1) continue;
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < strlen(str) - 1; i++) {
            if(str[i] == '"') {
                if(i - 1 >= 0) {
                    if(str[i - 1] != '\\') cnt++;
                }
                else cnt++;
            }
            if(str[i] == '/' && str[i + 1] == '/' && cnt % 2 == 0 && !flag) {
                ans++;
                break;
            }
            else if(str[i] == '/' && str[i + 1] == '/'&& flag) i++;
            else if(str[i] == '/' && str[i + 1] == '*' && cnt % 2 == 0) {
                flag = true;
                i++;
            }
            else if(flag && str[i] == '*' && str[i + 1] == '/') {
                ans++;
                flag = false;
                i++;
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
