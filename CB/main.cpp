// hihoCoder.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
using namespace std;

int slove(string s, int cnt)
{
    if(s.length() <= 1) return cnt;
	for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            char c = s[i];
            s[i] = '0';
            cnt++;
            i++;
            while (i < s.length() && s[i] == c) {
                s[i] = '0';
                cnt++;
                i++;
            }
            i--;
        }
	}
	string str ="";
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			str += s[i];
		}
		else {
			flag = true;
		}
	}
	if (flag) return slove(str, cnt);
	else return cnt;
}

int main()
{
	int T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		int ans = -1;
		for (int i = 0; i < s.length(); i++) {
            string str = "";
            for (int j = 0; j < s.length(); j++) {
                if(j == i) str += s[i];
                str += s[j];
            }
            str[i] = 'A';
			int temp = slove(str, 0);
			if (ans < temp) {
				ans = temp;
			}
			str[i] = 'B';
			temp = slove(str, 0);
			if (ans < temp) {
				ans = temp;
			}
			str[i] = 'C';
			temp = slove(str, 0);
			if (ans < temp) {
				ans = temp;
			}
		}
		cout << ans << endl;
	}
    return 0;
}

