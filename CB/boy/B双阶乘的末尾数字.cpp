#include <iostream>
#define LL long long
using namespace std;

int main()
{
    LL T, x, k;
    cin >> T;
    while(T--) {
        cin >> x >> k;
        bool flag = false;
        for(LL y = x; y > 0; y -= 2) {
            LL temp = x - y;
            LL tmp = 1, zz = x;
            for(LL i = 0; i < temp; i++) {
                tmp *= zz;
                zz -= 2;
                tmp %= 10000;
            }
            if(tmp % 10 == k) {
                cout << y << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}
