#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define maxn 10005
#define LL long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int Y,M,D;
        char ch;
        scanf("%d%c%d%c%d", &Y,&ch,&M,&ch,&D);
        int tmp = 0;
        for(int i = Y + 1; i < Y + 1000; i++) {
            int year;
            if(M <= 2) {
                year = i - 1;
            }
            else {
                year = i;
            }
            int day = 365;
            if((year % 4 == 0 && year % 100 != 0)||year % 400 == 0) {
                day = 366;
            }
            tmp = (tmp + day) % 7;
            if(tmp == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}


