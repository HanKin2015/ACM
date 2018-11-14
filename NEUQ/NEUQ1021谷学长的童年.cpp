#include <iostream>
#include <iomanip>
using namespace std;

double Solve(int N, double p[])
{
    double ans = 0;
    for (int msk = 1; msk < (1 << N); msk++) {  // 子串有2^k种可能
        int bits = 0;
        double mult = 0;
        /*每种可能用bit位表示，最多k位，然后看bit位上是否形成组合*/
        for (int i = 0; i < N; i++) {
            if (msk & (1 << i)) {
                bits++;
                mult += p[i];
            }
        }
        double cur = 1 / mult;
        //cout << cur << endl;
        if (bits % 2 == 1) ans += cur;
        else ans -= cur;
    }
    return ans;
}

int main()
{
    int N;
    double p[25];
    while (cin >> N) {
        for (int i = 0; i < N; i++) cin >> p[i];
        cout << fixed << setprecision(3) << Solve(N, p) << endl;
    }
    return 0;
}
