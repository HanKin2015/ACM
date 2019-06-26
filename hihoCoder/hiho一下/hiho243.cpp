#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;
	int cnt[100005][3];  // 当前位置前面有多少
	memset(cnt, 0, sizeof(cnt));
	int len = S.size();
	if (len < 4) {
		cout << -1 << endl;
		return 0;
	}
	int ans = len;
	for (int i = 1; i <= len; i++) {
		cnt[i][0] = cnt[i - 1][0];
		cnt[i][1] = cnt[i - 1][1];
		cnt[i][2] = cnt[i - 1][2];
		if (S[i - 1] == 'h') cnt[i][0]++;
		if (S[i - 1] == 'i') cnt[i][1]++;
		if (S[i - 1] == 'o') cnt[i][2]++;
	}
	bool flag = false;
	for (int L = 0; L < len; L++) {
	    //cout << L << ' ' << ans << endl;
        for (int R = L + 4; R <= L + ans; R++) {
            int a = cnt[R][0] - cnt[L][0];
            int b = cnt[R][1] - cnt[L][1];
            int c = cnt[R][2] - cnt[L][2];
            //cout << a << ' ' << b << ' ' << c << endl;
            int tmp = R - L;
            if (a > 2 || b > 1 || c > 1) break;
            if (a == 2 && b == 1 && c == 1 && tmp < ans) {
                ans = tmp;
                flag = true;
                break;
            }
        }
        //cout << endl;
	}
	if (!flag) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
