#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

/**
*根据分隔符c进行字符串分割
*/
inline void SplitStr(string& s, vector<int>& v, const string& c)
{
	string title;
	transform(s.begin(), s.end(), back_inserter(title), ::tolower);
	s = "";
	for (int i = 0; i < title.size(); i++) {
		if ((title[i] >= '0' && title[i] <= '9') || title[i] == ' ') {
			s += title[i];
		}
	}
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2) {
        string str = s.substr(pos1, pos2 - pos1);
        int tmp = 0;
        for (int i = 0; i < str.size(); i++) tmp = tmp * 10 + str[i] - '0';
		v.push_back(tmp);

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length()) {
        string str = s.substr(pos1);
        int tmp = 0;
        for (int i = 0; i < str.size(); i++) tmp = tmp * 10 + str[i] - '0';
		v.push_back(tmp);
	}
	return;
}

const int maxn = 1e3 + 4;

int main()
{
    int max_x = -1;
    char str_p[maxn];
    cin.getline(str_p, maxn);
    string tmp_p = str_p;
    vector<int> p;
    SplitStr(tmp_p, p, " ");
    int cnt_p[maxn] = {0};
    for (int i = 0; i < p.size(); i++) {
        //cout << p[i] <<endl;
        cnt_p[p[i]]++;
        if (max_x < p[i]) max_x = p[i];
    }

    char str_q[maxn];
    cin.getline(str_q, maxn);
    string tmp_q = str_q;
    vector<int> q;
    SplitStr(tmp_q, q, " ");
    int cnt_q[maxn] = {0};
    for (int i = 0; i < q.size(); i++) {
        //cout << q[i] <<endl;
        cnt_q[q[i]]++;
        if (max_x < q[i]) max_x = q[i];
    }

    int lenP = p.size(), lenQ = q.size();
    double ans = 0;
    for (int i = 1; i <= max_x; i++) {
        double proP = cnt_p[i] * 1.0 / lenP;
        double proQ = cnt_q[i] * 1.0 / lenQ;
        ans += proP * log2(proP / proQ);
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}

/*
1 1 1 2 3 4 1 2 3 4 1 3 4 1 2 3 3 1 2 3 1 2 3 1 3 1
2 2 2 2 3 4 4 2 2 1 2 4 3 2 2 1 3 4 4 2 4 3
*/
