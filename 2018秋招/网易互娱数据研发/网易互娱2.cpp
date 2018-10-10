#include <bits/stdc++.h>
#include <iomanip>
#define LL long long
using namespace std;

const int maxn = 1e7 + 5;
const double eps = 1e-4;

struct ST {
    LL login, logout;
    LL online;
    int roleid;
};

bool cmp(ST a, ST b) {
    return a.roleid < b.roleid;
}

ST newRole[maxn];
ST role[maxn];

int main()
{
    string type;
    string data;

    for (int i = 0; i < maxn; i++) {
        role[i].logout = -1;
    }
    while (cin >> data) {
        int len = data.size();
        LL time = 0, roleid = 0;
        string type = "";
        bool flag1 = true, flag2 = true, flag3 = false;
        for (int i = 0; i < len; i++) {
            if (data[i] == '[') continue;
            if (data[i] == ']') {
                if (!flag1) flag2 = false;
                flag1 = false;
                continue;
            }
            if (flag1) time = time * 10 + data[i] - '0';
            if (data[i] == '\"' && flag3) flag3 = false;
            if ((i > 2 && data[i - 1] == '\"' && data[i - 2] == ':') || flag3) {
                flag3 = true;
                roleid = roleid * 10 + data[i] - '0';
            }
            if (!flag1 && flag2) type += data[i];
        }
        //cout << time << ' ' << type << ' ' <<roleid << endl;
        if (type == "login") role[roleid].login = time;
        else if (type == "logout") role[roleid].logout = time;
    }

    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (role[i].logout != -1) {
            newRole[cnt].login = role[i].login;
            newRole[cnt].logout = role[i].logout;
            newRole[cnt].online = role[i].logout - role[i].login;
            newRole[cnt++].roleid = i;
        }
    }
    sort(newRole, newRole + cnt, cmp);
    int ans1[maxn], ans2[maxn], dex = 0;
    set<int> ans;
    LL tmp = -1;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            LL a = max(newRole[i].login, newRole[j].login);
            LL b = min(newRole[i].logout, newRole[j].logout);
            LL val = (b - a) * 2.0 / (newRole[i].online + newRole[j].online);
            if (val > tmp) {
                tmp = val;
                dex = 0;
                ans.clear();
            }
            if (abs(tmp - val) < eps) {
                ans.insert(newRole[i].roleid);
                ans.insert(newRole[j].roleid);
                ans1[dex] = newRole[i].roleid;
                ans2[dex++] = newRole[j].roleid;
            }
        }
    }
    for (int i : ans) cout << i << endl;
    return 0;
}

