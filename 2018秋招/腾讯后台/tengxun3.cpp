#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int> > graph(maxn);
    for (int i = 0; i < m; i++) {
        int u, v ;
        cin >> u >> v;
        if(u == v) continue;
        graph[u].insert(v);
    }
    int out[maxn] = {0}, in[maxn] = {0};

    for(int i = 1; i <= n; i++) {
        queue<int> q;
        set<int> used = {i};
        q.push(i);
        while(!q.empty()) {
            int root = q.front();
            q.pop();
            for(int elem : graph[root]) {
                if(used.find(elem) != used.end()) continue;
                used.insert(elem);
                q.push(elem);
                in[elem]++, out[i]++;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] > out[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
