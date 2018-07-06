#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum[20] = { 0 }, temp[20] = { 0 };
    for(int i = 1; i < 20; i++) {   //i为第几天
        temp[i] = pow(2, i - 1);
        //cout << temp[i] << endl;
        sum[i] = sum[i - 1] + temp[i];
        cout << sum[i] << endl;
    }
    int N, M;
    while(cin >> N >> M) {
        cout << N << ' ' << M << endl;
        for(int i = 18; i > 0; i--) {
            if(M >= sum[i]) {
                for(int j = temp[i]; ; j++) {
                    int all = j;
                    int next_day = (j + 1) / 2; //up to integer
                    while(next_day != 1) {
                        all += next_day;
                        next_day = (next_day + 1) / 2;
                    }
                }
            }
        }
    }
    return 0;
}

/*
3 7 4
1 2 4 8 16

7 >= 7

3 - 3 = 0

3  8
8 >= 7
day = 3 - 3 = 0

3 9   6?
6 3 2
5 3 2
4 2 1

*/

