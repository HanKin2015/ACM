#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    cout << s.size() << endl;
    s.insert(1);
    s.insert(2);
    cout << s.size() << endl;
    s.clear();
    cout << s.size() << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        set<int> position[26], ans[55];
        string s1, s2;
        bool flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 55; j++) position[j].clear();
            cout << "second " << ans[0].size() << endl;
            cin >> s1 >> s2;
            for (int j = 0; j < M; j++) {
                position[s2[j] - 'a'].insert(j);
            }
            if (i == 0) {
                for (int j = 0; j < M; j++) {
                    for (int k : position[s1[j] - 'a']) ans[j].insert(k);
                    if (ans[j].size() == 0) flag = false;
                }
                cout << "fisrt " << ans[0].size() << endl;
            }
            else {
                cout << "nanyizhixin-hejian = ";
                for (int j = 0; j < M; j++) cout << ans[j].size() << ' ';
                cout << endl;
                for (int j = 0; j < M; j++) {
                    printf("ans%d size = %lld\n", j + 1, ans[j].size());
                    set<int> tmp;
                    for (int k : position[s1[j] - 'a']) {
                        for (int l : ans[j]) {
                            printf("i = %d: k = %d: l = %d\n", i, k, l);
                            if (k == l) tmp.insert(k);
                        }
                    }
                    ans[j].clear();
                    for (int k : tmp) ans[j].insert(k);
                    if (ans[j].size() == 0) flag = false;
                    tmp.clear();
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
            tmp.clear();
        }
    }
    return 0;
}