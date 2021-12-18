#include <bits/stdc++.h>
using namespace std;

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
					set<int>::iterator it = position[s1[j] - 'a'].begin();
					for (; it != position[s1[j] - 'a'].end(); it++) ans[j].insert(*it);
					if (ans[j].size() == 0) flag = false;
				}
			}
			else {
				for (int j = 0; j < M; j++) {
					set<int> tmp;
					set<int>::iterator it1 = position[s1[j] - 'a'].begin();
					for (; it1 != position[s1[j] - 'a'].end(); it1++) {
						set<int>::iterator it2 = ans[j].begin();
						for (; it2 != ans[j].end(); it2++) {
							if (*it1 == *it2) tmp.insert(*it1);
						}
					}
					ans[j].clear();
					set<int>::iterator it = tmp.begin();
					for (; it != tmp.end(); it++) ans[j].insert(*it);
					if (ans[j].size() == 0) flag = false;
				}
			}
		}
		if (!flag) cout << -1 << endl;
		else {
			set<int> tmp;
			for (int i = 0; i < M; i++) {
				set<int>::iterator it1 = ans[i].begin();
				for (; it1 != ans[i].end(); it1++) {
					flag = true;
					set<int>::iterator it2 = tmp.begin();
					for (; it2 != tmp.end(); it2++) {
						if (*it1 == *it2) flag = false;
					}
					if (flag) {
						cout << *it1 + 1;
						if (i == M - 1) cout << endl;
						else cout << ' ';
						tmp.insert(*it1);
						break;
					}
				}
			}
		}
	}
	return 0;
}



