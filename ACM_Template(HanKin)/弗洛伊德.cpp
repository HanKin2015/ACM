/*
1、初始化(邻接矩阵存储,不可达为无穷大,自身距离为0)
2、三重for循环:枚举举起点，终点，中间点
是动态规划的一个例子，状态转移方程：map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
 
 
Floyd-Warshall算法，该算法也称为Floyd算法，Roy-Warshall算法，Roy-Floyd算法或WFI算法。
采用松弛技术（松弛操作），对在i和j之间的所有其他点进行一次松弛
时间复杂度O(n^3)空间复杂度O(n^2)
求多源最短路径，求传递闭包
是动态规划的一个例子，状态转移方程：map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
松弛操作(relaxation)是指对于每个顶点v∈V，都设置一个属性d[v]，用来描述从源点s到v的最短路径上权值的上界，称为最短路径估计（shortest-path estimate）。
 
所以和迪杰斯特拉是一样的复杂度(多源)???
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX / 2;   // 要进行加法，不宜取最大值
 
void Floyd(int n, int dis[maxn][maxn])
{
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            for (int k = 1; k <= n; k++) {
               dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
 
    // 多源
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << "->" << j << ' ' << dis[i][j] << endl;
        }
   }
 
    // 单源
    int outset = 6;
    for (int i = 1; i <= n; i++) cout << outset << "->" << i << ' ' << dis[outset][i] << endl;
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
 
7 12
1 2 12
1 6 16
1 7 14
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
5 7 8
6 7 9
 
6
 
16
7
6
6
2
6->6 0
9
*/