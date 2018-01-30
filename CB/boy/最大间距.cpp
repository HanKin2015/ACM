#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, num[1005];
    while(cin >> n) {
        int temp[65536];
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < n; i++) {
            cin >> num[i];
            temp[num[i]] = 1;
        }
        if(n < 2) {
            cout << 0 << endl;
            continue;
        }
        int per = -1, ans = -1;
        for(int i = 0; i < 65536; i++) {
            if(temp[i]) {
                if(per == -1) {
                    per = i;
                    continue;
                }
                if(i - per > ans) ans = i - per;
                per = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
