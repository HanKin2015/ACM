#include <bits/stdc++.h>
#include <iomanip>
#define LL long long
using namespace std;

const int maxn = 1e7 + 5;
struct ST {
    LL id, age, height, weight;
    LL id1, id2;
    double val;
};

const double eps = 1e-9;
bool cmp(ST a, ST b) {
    if (a.id1 == b.id1) {
        if (abs(a.val - b.val) < eps) return a.id2 < b.id2;
        return a.val < b.val;
    }
    return a.id1 < b.id1;
}

LL compute(LL a, LL b)
{
    LL ans = (a - b)*(a - b);
    return ans;
}

ST table[maxn];
ST newTable[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, age, height, weight;
        cin >> id >> age >> height >> weight;
        table[i].id = id;
        table[i].age = age;
        table[i].height = height;
        table[i].weight = weight;
    }
    int cnt = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i].id != table[j].id) {
                double val = sqrt(compute(table[i].age, table[j].age) + compute(table[i].height, table[j].height) + compute(table[i].weight, table[j].weight));
                if (val < 20) {
                    s.insert(table[i].id);
                    newTable[cnt].id1 = table[i].id;
                    newTable[cnt].id2 = table[j].id;
                    newTable[cnt++].val = val;
                }
            }
        }
    }
    sort(newTable, newTable + cnt, cmp);
    int vis[maxn];   // group by id1
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < cnt; i++) {
        if (!vis[newTable[i].id1] && s.find(newTable[i].id1) != s.end()) {
            vis[newTable[i].id1] = 1;
            cout << newTable[i].id1 << ' ' << newTable[i].id2 << ' ';
            printf("%.2f\n", newTable[i].val);
        }
    }
    return 0;
}
