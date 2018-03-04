#include <iostream>
#define LL long long
using namespace std;

int main()
{
    LL T, x, k;
    cin >> T;
    while(T--) {
        //cin >> x >> k;
        for(x = 1; x <= 30; x++){
            for(k = 0; k <= 9; k++){
                cout << "x = " << x << "  k = "<<k <<"   ";
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
        }
    }
    return 0;
}

