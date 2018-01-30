#include <bits/stdc++.h>
using namespace std;

int N, L[100005], R[100005], high[100005][100005], tag = 1;

int main()
{
    memset(high, 0, sizeof(high));
    for(int i = 0; i < 1005; i++) high[0][i] = 1;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        for(int j = tag; j >= 0; j--) {
            bool flag = false;
            for(int k = L[i]; k <= R[i]; k++) {
                if(high[j][k]) {
                    if(j + 1 > tag) tag++;
                    cout << j + 1 << endl;
                    flag = true;
                    for(int l = L[i]; l <= R[i]; l++) high[j + 1][l] = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}
