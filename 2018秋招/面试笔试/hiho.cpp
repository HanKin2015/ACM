#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1e3 + 5;
const int maxv = 1e6;

int main()
{
    int N, X[maxn], Y[maxn];
    cin >> N;
    int **vis = new int*[maxv];
    for (int i = 0; i < maxv; i++) vis[i] = new int[maxv];
    //vector<vector<int> > vis(maxv, vector<int>(maxv, 0));
    map<pair<int, int>, bool> vis;   // default false, unorder_map no pair
    //unordered_map<LL, int> HASH;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        vis[make_pair(X[i], Y[i])] = true;
        //HASH[X[i] * maxv + Y[i]] = 1;
    }
    LL ans = 1e18;     // min area
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (X[i] == X[j] || Y[i] == Y[j]) continue;  // in a line, no rectangle
            if (vis[make_pair(X[i], Y[j])] && vis[make_pair(X[j], Y[i])]) {
            //if (vis.count(make_pair(X[i], Y[j])) != 0 && vis.count(make_pair(X[j], Y[i])) != 0) {
            //if (vis.find(make_pair(X[i], Y[j])) != vis.end() && vis.find(make_pair(X[j], Y[i])) != vis.end()) {
            //if (HASH[X[i] * maxv + Y[j]] && HASH[X[j] * maxv + Y[i]]) {
                LL tmp = (LL)abs(X[i] - X[j]) * abs(Y[i] - Y[j]);
                if (tmp < ans) ans = tmp;
            }
        }
    }
    if (ans != 1e18) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
