#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int maxn = 1e5 + 5;
    int N;
    cin >> N;
    string W[maxn], S;
    for (int i = 0; i < N; i++) cin >> W[i];
    cin >> S;
    int f[maxn][26] = {0};
    memset(f, 0, sizeof(f));
    for (int i = S.size() - 1; i > 0; i--) { // f[0]位置没有字母，但S还是从0开始   
        for (int j = 0; j < 26; j++) {
            f[i - 1][j] = f[i][j];
        }
        f[i - 1][S[i] - 'a'] = i;  
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        int len = W[i].size(), pos = 0;
        for (int j = 0; j < len; j++) {
            if (j == 0 && W[i][j] == S[0]) continue;
            pos = f[pos][W[i][j] - 'a'];
            if (pos == 0) {
                flag = false;
                break;
            }
        }
        if (flag) ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}