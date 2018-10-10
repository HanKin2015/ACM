#include <bits/stdc++.h>
using namespace std;

struct PAIR {
    int a, b;
};

bool cmp(PAIR x, PAIR y)
{
    return x.b < y.b;
}

int main()
{
    int N, a, b;
    PAIR noodles[105];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);  // ��֤a < b
        noodles[i].a = a;
        noodles[i].b = b;
    }
    sort(noodles, noodles + N, cmp);
    int ans = 0, tmp = INT_MIN;
    for (int i = 0; i < N; i++) {
        // ���ԣ�С�����a�����ϣ�Ȼ�����tmpδ�յ�b
        if (tmp <= noodles[i].a) {
            ans++;
            tmp = noodles[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}
