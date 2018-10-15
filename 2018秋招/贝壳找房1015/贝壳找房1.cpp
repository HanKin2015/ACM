#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
typedef long long LL;

int main()
{
    LL T, X, A, C, B, D, Y;
    cin >> T;
    while (T--) {
        cin >> X >> A >> C >> Y >> B >> D;
        LL XIAOZHI = (X / B - 1) * D;  // 不用判断X是否小于等于B
        if (X % B != 0) XIAOZHI += D;

        LL XIAOCHUN = (Y / A - 1) * C;
        if (Y % A != 0) XIAOCHUN += C;

        if (XIAOCHUN == XIAOZHI) puts("TIE");
        else if (XIAOCHUN < XIAOZHI) puts("XIAOZHI");
        else puts("XIAOCHUN");
    }
    return 0;
}
