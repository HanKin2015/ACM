#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":" << endl;
		int n, q;
		cin >> n >> q;
		char A[maxn];
		cin >> A;

		int count[maxn][26] = {0};
		count[0][A[0] - 'A'] = 1;
		for (int j = 1; j < strlen(A); j++) {
			int character = A[j] - 'A';
			for (int k = 0; k < 26; k++) {
				if (k == character) count[j][k] = count[j - 1][k] + 1;
				else count[j][k] = count[j - 1][k];
			}
		}

		int l, r;
		while (q--) {
			cin >> l >> r;
			for (int j = 0; j < 26; j++) {
				int ans = count[r][j] - count[l - 1][j];
				if (ans != 0) {
					cout << ans << endl;
					break;
				}
			}
		}
	}
	return 0;
}
