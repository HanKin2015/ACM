#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    const int mod = 1e9 + 7;

    string str;
    cin >> str;
    LL cnt[10][10][2005];   // 两个位置形成末尾共有多少的前缀
    memset(cnt, 0, sizeof(cnt));

    int len = str.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int head = str[i] - '0';
            int tail = str[j] - '0';
            cnt[head][tail][i]++;
        }
    }

    static LL C[2005][2005];  // 组合数
    for(int i = 0; i < len; i++) {
        C[i][i] = C[i][0] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= mod;
        }
    }

    int Q, N, X, Y;
    char A, B;
    cin >> Q;

    // 优化
    static LL ret[10][10][2005]; // 存储结果，如果是相同的询问避免重复计算
    bool vis[10][10][2005];
    while (Q--) {
        cin >> N >> A >> B;  // 不能写成一个数的输入，可能有前缀0
        //cout << A << B << endl;
        X = A - '0';
        Y = B - '0';
        LL ans = 0;
        if (N > 1 && N <= len) {
            if (vis[X][Y][N]) ans = ret[X][Y][N];
            else {
                int M = N - 2;
                for (int i = 0; i < len; i++) {  // 时间复杂度O(5*10^5*10^3=10^8)
                    if (cnt[X][Y][i] && i >= M) { // 一定要满足组合数条件
                        ans += C[i][M] * cnt[X][Y][i];
                        ans %= mod;
                    }
                }
                ret[X][Y][N] = ans;
                vis[X][Y][N] = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
输入：
312121
4
2 21
3 31
4 22
3 22

输出：
3
0
1
2

提交WA了9次，提交AC了才能看别人的代码。

居然是组合数求错了。。。。。
不可能啊。。。。。。
*/
