#include <iostream>
#include <cmath>
#define LL long long
using namespace std;

int main()
{
    LL N;
    while(cin >> N) {
        if(N == 0) {
            cout << 0 << endl;
            continue;
        }
        LL cnt = 1, temp = 9;
        for(int i = 1; i < 20; i++) {   //Ñ°ÕÒÎ»Êý
            cnt += (temp * i);
            if(cnt >= N) {
                LL tmp = N - (cnt - temp * i);
                LL n = tmp / i, ans = tmp % i;
                n = n + pow(10, i - 1);
                int arr[25], tag = 0;
                while(n) {
                    arr[tag++] = n % 10;
                    n /= 10;
                }
                cout << arr[tag - ans - 1] << endl;
                break;
            }
            temp *= 10;
        }
    }
}
