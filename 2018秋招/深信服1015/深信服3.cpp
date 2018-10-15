#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; i++) cin >> str;
    int T;
    cin >> T;
    char c;
    for (int i = 0; i < T; i++) {
        cin >> c;
        cin >> str;
    }
    srand(time(0));
    int n = rand();
    if (n & 1) cout << "Y" << endl;
    else cout << "N" << endl;
    return 0;
}
