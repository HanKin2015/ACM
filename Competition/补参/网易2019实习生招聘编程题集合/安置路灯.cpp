/*
*我咋没想到最简单的做法：当遇到.的时候就往后移动3个单位
*/

#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n, ans = 0, temp = 0; //temp记录前面有多少个位置需要点亮
        char broad[1005];
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> broad[i];
        }
        for(int i = 0; i < n; i++) {
            if(broad[i] == '.') temp++;
            if(temp == 3) {
                ans++;
                temp = 0;
            }
            if(broad[i] == 'X' && temp == 2) {
                ans++;
                temp = 0;
            }
            if(broad[i] == 'X' && temp == 1) {
                ans++;
                temp = 0;
                i++;
            }
        }
        if(temp) ans++;
        cout << ans << endl;
    }
    return 0;
}
