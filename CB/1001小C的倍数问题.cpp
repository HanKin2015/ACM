#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define LL long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int P;
        cin >> P;
        int cnt = 0;
        for(int i = 1; i < maxn; i++) {
            bool flag = true;
            for(int j = 1; j < 10; j++) {
                LL tmp = i * j;
                int sum = 0;
                while(tmp) {
                    sum += (tmp % P);
                    tmp /= P;
                }
                if(sum % i) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt++;
                //cout << i <<' ';
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

