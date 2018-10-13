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
		int l, r;
		while (q--) {
			cin >> l >> r;
			int ans = 1;
			char ch = A[l - 1];
			for (int j = l; j < r; j++) {
				if (A[j] == ch) ans++;
				else if (A[j] < ch) {
					ch = A[j];
					ans = 1;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
