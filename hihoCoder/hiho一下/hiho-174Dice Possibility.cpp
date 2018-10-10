#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    double d[105][605];
    memset(d, 0, sizeof(d));
    for(int i = 1; i <= 6; i++) d[1][i] = 1.0/6;
    for(int i = 2; i <= N; i++) {
        for(int j = i; j <= N * 6; j++) {
            for(int v = 1; v <= 6 && j - v >= i - 1; v++) {
                d[i][j] += d[i - 1][j - v] * (1.0/6);
            }
        }
    }
    cout << fixed << setprecision(2) << d[N][M] * 100 << endl;
    return 0;
}
