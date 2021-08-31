#include <bits/stdc++.h>
using namespace std;
1104  2697  3638  3630
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		set<int> ans[55];
		string s1, s2;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			set<int> position[26];
			cin >> s1 >> s2;
			for (int j = 0; j < M; j++) {
				position[s2[j] - 'a'].insert(j);
			}
			if (i == 0) {
				for (int j = 0; j < M; j++) {
					for (int k : position[s1[j] - 'a']) ans[j].insert(k);
					if (ans[j].size() == 0) flag = false;
				}
			}
			else {
				for (int j = 0; j < M; j++) {
					set<int> tmp;
					for (int k : position[s1[j] - 'a']) {
						for (int l : ans[j]) {
							if (k == l) tmp.insert(k);
						}
					}
					ans[j].clear();
					for (int k : tmp) ans[j].insert(k);
					if (ans[j].size() == 0) flag = false;
				}
			}
		}
		if (!flag) cout << -1 << endl;
		else {
			set<int> tmp;
			for (int i = 0; i < M; i++) {
				for (int j : ans[i]) {
					flag = true;
					for (int k : tmp) {
						if (j == k) flag = false;
					}
					if (flag) {
						cout << j + 1;
						if (i == M - 1) cout << endl;
						else cout << ' ';
						tmp.insert(j);
						break;
					}
				}
			}
		}
	}
	return 0;
}



