#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    string s1, s2;
    cin >> s1;
    int a[100005], b[100005];
    map<int, set<int> > cnt1, cnt2;
    set<pair<int, int> > st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cnt1[a[i]].insert(b[i]);
            cnt2[b[i]].insert(a[i]);
            int x = a[i], y = b[i];
            if(x > y) swap(x, y);
            st.insert(make_pair(x, y));
        }
    }
    return 0;
}



