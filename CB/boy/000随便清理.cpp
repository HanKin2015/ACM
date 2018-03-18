#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y = 6;
    x = y = 3;
    cout << x << endl;
    cout << y << endl;

    char s[] = "hejian";
    char *str = s;
    int A = 234;
    int *B = &A;
    cout << *B << endl;
    *str++;
    str = "opsu";
    cout << *str << endl;

    int a = 1, b = -1;
    int ret = (a&b)|(((~a) ^ 1)&((~b)^1));
    //ret = (a ^ b) ^ 1;
    ret = ~(a ^ b);
    ret = a ^ b;
    cout << ret << endl;

    int N, M;
    cin >> N >> M;
    if(N == 1) {
        cout << M << endl;
        return 0;
    }
    int ans = pow(M - 1, N) + pow(-1, N) * (M - 1);
    cout << ans << endl;
    return 0;
}
