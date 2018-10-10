#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    if (n * m % p != 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int cnt = 1, mat[105][105];
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    //cout << i << ' ' << j << endl;
                    if (m - j >= p) {
                        for (int k = j; k < j + p; k++) mat[i][k] = cnt;
                        j += p - 1;   // 因为后面j还会+1
                    }
                    else {
                        for (int k = i; k < i + p; k++) mat[k][j] = cnt;
                    }
                    cnt++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
