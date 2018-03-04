#include <bits/stdc++.h>
using namespace std;

int main()
{
    //题解真聪明，寻找c用set(倒序存储)，寻找a用map
    map<int, int> cnt;
    set<pair<int, int> > S;
    int N, A; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A;
        cnt[A]++;
    }
    for(pair<int, int> it : cnt) {
        S.insert(make_pair(it.second, it.first));
    }

    if((--S.end())->first > (N + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    int pre = -213;
    for(int i = 0; i < N; i++) {
        int x;
        if((--S.end())->first * 2 - 1 == N - i) {
            x = (--S.end())->second;
        }
        else {
            for(pair<int, int> it : cnt) {
                if(it.first != pre) {
                    x = it.first;
                    break;
                }
            }
        }
        cout << x << ' ';
        pre = x;
        if(--cnt[x] > 0) {
            S.erase(make_pair(cnt[x] + 1, x));
            S.insert(make_pair(cnt[x], x));
        }
        else {
            S.erase(make_pair(cnt[x] + 1, x));
            cnt.erase(x);
        }
    }
    return 0;
}
