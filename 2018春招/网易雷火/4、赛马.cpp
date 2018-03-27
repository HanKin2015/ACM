#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += 1.0 / i;
    }
    /*
    int horse[1005];
    for(int i = 0; i <= N; i++) horse[i] = i;  //增加0是为了最后一匹马都会活下来
    int num = 0;
    do {
        num++;
        for(int i = N; i > 0; i--) {
            bool flag = true;
            for(int j = i - 1; j >= 0; j--) {
                if(horse[i] < horse[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
    }while(next_permutation(horse + 1, horse + N + 1));
    */
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}
