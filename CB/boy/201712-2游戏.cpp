#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int n, k, flag[1005];
    cin >> n >> k;
    memset(flag, 0, sizeof(flag));
    int cnt = 0, current = 1, index = 1;
    while(cnt != n - 1) {
        if(!flag[index]) {
            if(current % k == 0 || current % 10 == k) {
                cnt++;
                flag[index] = 1;
            }
            current++;
        }
        index++;
        if(index == n + 1) index = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(!flag[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

