#include <bits/stdc++.h>
using namespace std;

double f[105][105][105], S[105][105][105];

int main()
{
    int N, M, A[105], B[105];
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    memset(f, 0, sizeof(f));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int l = 0; l < N; l++) {
                    S[i][l][j] = 0.5 * abs(A[j]*B[l] - A[j]*B[i] - A[i]*B[l] + B[i]*A[l] - A[l]*B[j] + A[i]*B[j]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j != i; j = (j + 1) % N) {
            for(int l = i + 1; l != j; l = (l + 1) % N) {
                for(int k = 3; k <= N; k++) {
                    f[i][j][k] = max(f[i][l][k - 1] + S[i][l][j], f[i][j][k]);
                }
            }
        }
    }
    double ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, f[i][j][M]);
		}
	}
	cout << f[0][N - 1][M] << endl;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
