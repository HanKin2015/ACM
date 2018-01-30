#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-9
using namespace std;

int main()
{
    int N;
    while(cin >> N) {
        double p[25], sum = 0, ans = 0;
        for(int i = 0; i < N; i++) {
            cin >> p[i];
            sum += p[i];
            ans += (1.0 / p[i]);
        }
        if(abs(sum - 1) > eps && N > 1) {
            ans -= (1.0 /( 1 - sum));
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
