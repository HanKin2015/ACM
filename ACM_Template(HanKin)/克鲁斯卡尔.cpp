/*
1、定义边的结构体(需要对边进行排序)
2、排序
3、从小到大选择边，每次加入边的时候至少有一个新的节点加入
 
时间复杂度：ElogE
 
 
最小生成树(Minimum Spanning Tree,MST)
包含原图中的所有 n 个结点，并且有保持图连通的最少的边。
最小生成树可以用kruskal（克鲁斯卡尔）算法或prim（普里姆）算法求出。
最小生成树其实是最小权重生成树的简称。
 
// 最小生成树和最短路径到底有什么不同 //
最小生成树可能有多个，只是保证树的所有权总和最小并且包括所有点。两点的路径不一定是最短路径
Dijkstra和Prim比较像，不过Dijkstra需要松弛最短距离
一个图如果有负权环...路径长可以无穷小，但生成树的权值一定是有限的
如：
1---(1)---2
|       / |
(1) (1) (1)
| /       |
4---(1)---3
求点1到点2的最短路径，这能用最小生成树求么？
(一个三角形三边为3、4、5。生成树为3+4=5，而不是直角点的最短路径为3+5或4+5)
 
 
最小生成树是无向，而最短路径可以有向
最小生成树是保证无向图每两点间可以互相到达，并且边权之和最小
最短路径...是保证起点可到达终点（有向图中不要求终点能到起点），并且路径权值之和最小
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
    Kruskal(n, m, edge);   // 单源起点，边集合，顶点数量
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