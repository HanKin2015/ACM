#include <bits/stdc++.h>
using namespace std;

int digui(int head, string s, int len)
{
	int ans = 1;
	for (int i = head; i < len; i++) {
		if (s[i] == '?') {
			ans += 1;
			s[i] = '*';
		}
		else if (i + 1 < len && s[i + 1] == '?') {
			ans += digui(head + 1, s, len);
		}
		else if (s[i] == '^') ans ^= 1;
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.size();
		cout << digui(0, s, len) << endl; 
	}
	return 0;
}



