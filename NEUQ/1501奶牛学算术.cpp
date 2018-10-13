#include <iostream>
#include <cmath>
#include <string.h>
#define LL long long
using namespace std;

int main()
{
    LL t, x, k;
    cin >> t;
    while(t--){
        cin >> x >> k;
        int arr[1005], ans[1005], tag = 0;
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        while(x) {
            arr[tag++] = x % 2;
            x >>= 1;
        }
        tag = 0;
        while(k) {
            ans[tag++] = k % 2;
            k >>= 1;
        }
        int maxn = tag;
        tag = 0;
        LL temp = 1, ret = 0;
        for(int i = 0; ; i++) {
            if(arr[i] == 0) {
                if(ans[tag] == 1) ret += temp;
                tag++;
                if(tag == maxn) break;
            }
            temp <<= 1;
        }
        cout << ret << endl;
    }
    return 0;
}
