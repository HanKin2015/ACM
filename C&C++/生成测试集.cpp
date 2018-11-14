#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("test.txt", "w", stdout);
    const int T = 10000, maxn = 11;
    cout << T << endl;
    int seed = time(0);
    srand(seed);
    int m, n;
    cin >> m >> n;
    for (int index = 0; index < T; index++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = rand() % maxn;
                cout << num << ' ';
            }
            cout << endl;
        }
    }
    fclose(stdout);
    return 0;
}

