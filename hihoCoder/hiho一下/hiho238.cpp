#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 1;

using ll = long long;

int N, M, K;

struct Node {
    int tot = 0;  // 权值
    vector<Node* > children;
} nodes[MAXN];

void GenTot(Node* root) {
    for (Node * child : root->children) {
        GenTot(child);
        root->tot += child->tot;
    }
}

int dfs(Node* root, ll& ans) {
    int cnt = 0;  // 子节点等于K的个数
    vector<int> rets;
    for (Node* child : root->children) {
        int t = dfs(child, ans);
        rets.emplace_back(t);
        cnt += t;
    }
    ll tmp = 0;
    // 比如rets = {1, 2, 3, 3}， 下面的三行相当于ans += 1*2 + 1*3 + 1*4 + 2*3 + 2*4 + 3*4
    for (int ret : rets)
        tmp += 1LL * (cnt - ret) * ret;  // 计算题目分析中的ans1
    ans += tmp / 2;
    if (root->tot == 2 * K && root != &nodes[0]) {
        ans += cnt;  // 计算题目分析中的ans2
    }
    return cnt + (root->tot == K ? 1 : 0);
}

ll Solution() {
    GenTot(&nodes[0]);
    int tot = nodes[0].tot;
    return tot;
    if (tot % 3 != 0)
        return 0;
    ll ans = 0;
    K = tot / 3;
    dfs(&nodes[0], ans);
    return ans;
}

int main() {
    int T;
    int v, p;
    while (cin >> T) {
        while (T--) {
            cin >> N;
            for (int i = 0; i <= N; i++) {
                nodes[i].tot = 0;
                nodes[i].children.clear();
            }

            for (int i = 1; i <= N; i++) {
                cin >> v >> p;
                nodes[i].tot = v;
                nodes[p].children.emplace_back(&nodes[i]);
            }
            cout << Solution() << '\n';
        }
    }
    return 0;
}
