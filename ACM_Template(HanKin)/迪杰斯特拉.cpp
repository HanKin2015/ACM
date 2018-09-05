/*
1、初始化(邻接矩阵存储,不可达为无穷大,自身距离为0)
2、定义单源起点
3、遍历n次:
           更新前一点到达所有点的距离(前一点是单源到达的最短点)
           选取所有点的距离中最小值(对前一点加入已访问标记)
 
 
又叫狄克斯特拉算法
该算法复杂度为n^2,如果边数远小于n^2,对此可以考虑用堆这种数据结构进行优化
取出最短路径的复杂度降为O(1)；每次调整的复杂度降为O（elogn）；e为该点的边数
所以复杂度降为O((m+n)logn)
单源最短路径问题
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX;
int dis[maxn]; // 记录最短距离大小
 
 
// 使用了广度优先搜索解决赋权有向图或者无向图的单源最短路径问题
void Dijkstra(int n, int edge[maxn][maxn], int outset)
{
    // 记录点已经被访问选择，最先选择的一定是最短的，后面不会再次更新
    bool vis[maxn];
    memset(vis, 0, sizeof(vis));
 
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[outset] = 0;    // 设置单源起点，这样就n2复杂度；如果多源就n3复杂度。
 
    int preNode = outset, path[maxn];     // 记录每个点的前一个点(唯一),这样便可以打印路径
    int select[maxn];   // 记录每次选择的最短点
    for (int cnt = 1; cnt <= n; cnt++) {     // n个顶点就要遍历n次
        int minNode = outset, minDis = inf;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] < minDis) {  // 选择前一个点到所有点的边中最短
                minDis = dis[i];
                minNode = i;
            }
        }
        while (edge[preNode][minNode] == inf) preNode = path[preNode]; // 精髓
        path[minNode] = preNode;
        preNode = minNode;
        vis[minNode] = 1;
        select[cnt] = minNode;
        for (int i = 1; i <= n; i++) {       // 更新到达每个点的最短距离
            //点未访问，前一个点和当前点之间有边，距离变短则更新
            if (!vis[i] && edge[minNode][i] != inf && dis[minNode] + edge[minNode][i] < dis[i]) {
                dis[i] = dis[minNode] + edge[minNode][i];
            }
 
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << select[i] << ' ' << dis[select[i]] << endl;
        // 反向打印路径
        int cur = select[i];
        cout << cur;
        for (; cur != path[cur];) {
            cur = path[cur];
            cout << "<-" << cur;
        }
        cout << endl;
    }
    return;
}
 
int main()
{
    int n, m, u, v, w, edge[maxn][maxn];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edge[i][j] = inf;
        }
        edge[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edge[u][v] = w;
        edge[v][u] = w;
    }
    Dijkstra(n, edge, 6);   // 顶点数量，边集合，单源起点
    return 0;
}
 
/*
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
 
6 5
1 2 1
2 3 2
3 5 1
2 4 5
4 6 1
*/