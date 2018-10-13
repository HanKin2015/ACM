// pair居然能直接进行sort排序
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    int N, X, Y;
    pair<int, int> A[maxn];
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    sort(A, A + N);
    bool flag = true;
    int l = X, r = X, ans = 1;
    for (int i = 0; i < N; i++) {
        if (A[i].first <= l) {
            if (A[i].second > r) r = A[i].second;
        }
        else {
            ans++;
            l = r;
            if (A[i].first <= l) {
                if (A[i].second > r) r= A[i].second;
            }
            else {
                flag = false;
                break;
            }
        }
        if (r >= Y) break;
    }
    if (!flag) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

