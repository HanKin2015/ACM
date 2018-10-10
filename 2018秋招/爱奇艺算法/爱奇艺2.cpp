#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = -10; i < 11; i++) {
        int ret = i ^ -1;
        printf("-1 ^ %d = %d\n", i, ret);
    }





    int N, M, P;
    cin >> N >> M >> P;
    int A[1005], cnt[1005];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[i] = A[i];
    }
    for (int i = 0; i < M; i++) {
        char ch;
        int id;
        cin >> ch;
        cin >> id;
        if (ch == 'A') cnt[id - 1]++;
        else cnt[id - 1]--;
    }
    int tmp = cnt[P - 1], ans = 1;
    sort(cnt, cnt + N);
    for (int i = N - 1; i >= 0; i--) {
        if (cnt[i] == tmp) {
            cout << N - i << endl;
            return 0;
        }
    }
    return 0;
}

