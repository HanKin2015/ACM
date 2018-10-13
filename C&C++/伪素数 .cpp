#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int QuickPow(int a, int b, int mod)
{
    int ret = 1;
    a = a % mod;
    while(b) {
        if(b & 1) ret =( ret * a )% mod;
        a =( a * a )% mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    for(int i = 2; i < 800000; i++) {
        if(QuickPow(2, i - 1, i) == 1) {
            if(!IsPrime(i)) {
                cout << i << endl;
            }
        }
    }
    return 0;
}
