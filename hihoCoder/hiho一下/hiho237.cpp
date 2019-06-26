#include <bits/stdc++.h>
#define LL long long
#define maxn 100005
using namespace std;

struct Tree {
    int weight, sum = 0;
    vector<Tree* > children;
}nodes[maxn];

void GetSum(Tree* root)
{
    root->sum = root->weight;
    for (Tree* child : root->children) {
        GetSum(child);
        root->sum += child->sum;
    }
    return;
}

int S;
int dfs(Tree* root, int &ans)
{
    int cnt = 0;
    vector<int> rets;
    for (Tree* child : root->children) {
        int t = dfs(child, ans);
        rets.emplace_back(t);
        cnt += t;
    }
    int tmp = 0;
    for (int ret : rets) tmp += (cnt - ret) * ret;
    ans += tmp / 2;
    if (root->sum == 2 * S && root != *(nodes[0].children.begin())) ans += cnt;
    return cnt += (root->sum == S ? 1 : 0);
}

int Solution()
{

    Tree* root = *(nodes[0].children.begin());
    GetSum(root);
    int ans = root->sum;
    //cout << ans << endl;
    if (ans % 3 != 0) return 0;
    S = ans / 3;
    ans = 0;
    dfs(root, ans);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int N, V, P;
        cin >> N;
        for (int i = 0; i < N; i++) nodes[i].children.clear();
        for (int i = 1; i <= N; i++) {  // 根的父亲节点是0，所以第一个节点应该是1
            cin >> V >> P;
            nodes[i].weight = V;
            nodes[P].children.emplace_back(&nodes[i]);
        }
        cout << Solution() << endl;
    }

	return 0;
}

