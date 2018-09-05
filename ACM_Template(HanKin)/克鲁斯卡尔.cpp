/*
1������ߵĽṹ��(��Ҫ�Ա߽�������)
2������
3����С����ѡ��ߣ�ÿ�μ���ߵ�ʱ��������һ���µĽڵ����
 
ʱ�临�Ӷȣ�ElogE
 
 
��С������(Minimum Spanning Tree,MST)
����ԭͼ�е����� n ����㣬�����б���ͼ��ͨ�����ٵıߡ�
��С������������kruskal����³˹�������㷨��prim������ķ���㷨�����
��С��������ʵ����СȨ���������ļ�ơ�
 
// ��С�����������·��������ʲô��ͬ //
��С�����������ж����ֻ�Ǳ�֤��������Ȩ�ܺ���С���Ұ������е㡣�����·����һ�������·��
Dijkstra��Prim�Ƚ��񣬲���Dijkstra��Ҫ�ɳ���̾���
һ��ͼ����и�Ȩ��...·������������С������������Ȩֵһ�������޵�
�磺
1---(1)---2
|       / |
(1) (1) (1)
| /       |
4---(1)---3
���1����2�����·������������С��������ô��
(һ������������Ϊ3��4��5��������Ϊ3+4=5��������ֱ�ǵ�����·��Ϊ3+5��4+5)
 
 
��С�����������򣬶����·����������
��С�������Ǳ�֤����ͼÿ�������Ի��ൽ����ұ�Ȩ֮����С
���·��...�Ǳ�֤���ɵ����յ㣨����ͼ�в�Ҫ���յ��ܵ���㣩������·��Ȩֵ֮����С
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e3 + 5;
 
struct STRUCT {
    int v1, v2, weight;
};
 
bool cmp(STRUCT a, STRUCT b) {
    return a.weight < b.weight;
}
 
void Kruskal(int V, int E, STRUCT edge[maxn])
{
    sort(edge, edge + E, cmp);
    int vis[maxn], cnt = 0;
    memset(vis, 0, sizeof(vis));
    set<int> nodes;
    STRUCT mst[maxn];
    for (int i = 0; i < E; i++) {
        int u = edge[i].v1, v = edge[i].v2;
        if (0 == (vis[u] & vis[v])) {
            vis[u] = 1;
            vis[v] = 1;
            nodes.insert(u);
            nodes.insert(v);
            mst[cnt++] = edge[i];
        }
        if (nodes.size() == V) break;
    }
 
    for (int i = 0; i < cnt; i++) {
        cout << mst[i].v1 << ' ' << mst[i].v2 << endl;
    }
    return;
}
 
int main()
{
    int n, m, u, v, w;
    STRUCT edge[maxn];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge[i].v1 = u;
        edge[i].v2 = v;
        edge[i].weight = w;
    }
    Kruskal(n, m, edge);   // ��Դ��㣬�߼��ϣ���������
    return 0;
}
 
/*
5 5
1 2 4
1 3 5
2 3 3
3 4 1
3 5 2
*/