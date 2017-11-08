#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 10005
#define LL long long
using namespace std;

int main()
{
    int n = 8;
    for(int n = 2; n < 100; n++){
        cout << n << ":";
        int cnt = 0;
        for(int i = 1; i < maxn; i++) {
            bool flag = true;
            for(int j = 1; j < 100; j++) {
                int tmp = i * j;
                int sum = 0;
                while(tmp) {
                    sum += (tmp % n);
                    tmp /= n;
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

