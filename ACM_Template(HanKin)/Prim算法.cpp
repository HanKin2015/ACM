/*
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
const int inf = INT_MAX;
 
void Prim(int outset, int edge[maxn][maxn])
{
    int minDis[maxn];     // 记录点到最小生成树的最短距离
    for (int i = 1; i <= V; i++) minDis[i] = edge[outset][i];
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    vis[outset] = 1;
 
    for (int i = 0; i < V - 1; i++) {  // 需要寻找V - 1条边
int min = Integer.MAX_VALUE;
            //选出剩下顶点到生成数的最小边
            for(int j=0;j<nVerts;j++)
            {
                if(!vertexList[j].wasVisited && lowcost[j]<min)
                {
                    min = lowcost[j];
                    k=j;
                }
            }
            vertexList[k].wasVisited = true;
            System.out.println("----"+lowcost[k]+"----"+vertexList[k].label);
            //将顶点k并入生成树，并更新剩下顶点到该生成树的最小边
            for(int m=0;m<nVerts;m++)
            {
                //如果剩余顶点到k并入后的生成树的最小边小于并入前的生成树的最小边
                if(!vertexList[m].wasVisited && adjMat[k][m]<lowcost[m])
                    lowcost[m] = adjMat[k][m];
            }
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
    Floyd(n, edge);   // 单源起点，边集合，顶点数量
    return 0;
}