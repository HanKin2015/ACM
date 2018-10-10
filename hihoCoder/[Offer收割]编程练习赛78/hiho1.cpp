#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M) {
//        if (N == 0 && M == 0) {
//          cout << -1 << endl;
//          continue;
//        }
        if (N > M) {
            if ((M + 1) * 2 < N) cout << -1;
            else {
                while (N || M) {
                    for (int i = 0; i < 2 && i < N; i++) {
                        cout << 'A';
                        N--;
                    }
                    int tmp = 1;
                    if (M * 2 - 1 > N) tmp = 2;
                    for (int i = 0; i < tmp && i < M; i++) {
                        cout << 'B';
                        M--;
                    }
                }
            }
        }
        else {
            if ((N + 1) * 2 < M) cout << -1;
            else {
                while (N || M) {
                    for (int i = 0; i < 2 && i < M; i++) {
                        cout << 'B';
                        M--;
                    }
                    int tmp = 1;
                    if (N * 2 - 1 > M) tmp = 2;
                    for (int i = 0; i < tmp && i < N; i++) {
                        cout << 'A';
                        N--;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
