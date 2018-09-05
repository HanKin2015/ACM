/*
很糟糕，不要把最短路径算法和最小生成树算法混淆了。。。。
 
是 Bellman-Ford算法 的队列优化算法的别称
用于求含负权边的单源最短路径，以及判负权环
最坏情况下复杂度和朴素 Bellman-Ford 相同，为 O(VE)
为了避免最坏情况的出现，在正权图上应使用效率更高的Dijkstra算法。
 
贝尔曼-福特(Bellman-Ford)算法
其原理为连续进行松弛，在每次松弛时把每条边都更新一下
若在n-1次松弛后还能更新，则说明图中有负环，因此无法得出结果，否则就完成
Dijkstra算法无法判断含负权边的图的最短路。
如果遇到负权，在没有负权回路（回路的权值和为负，即便有负权的边）存在时，\
也可以采用Bellman - Ford算法正确求出最短路径。
 
动态逼近法
设立一个先进先出的队列用来保存待优化的结点，优化时每次取出队首结点u，\
并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，\
如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。\
这样不断从队列中取出结点来进行松弛操作，直至队列空为止。
 
一个很直观的理解就是由无权图的BFS转化而来。
 
SPFA算法有两个优化策略SLF和LLL
SLF：Small Label First 策略，设要加入的节点是j，队首元素为i，若dist(j)<dist(i)，则将j插入队首，否则插入队尾。
LLL：Large Label Last 策略，设队首元素为i，队列中所有dist值的平均值为x，若dist(i)>x则将i插入到队尾，\
查找下一元素，直到找到某一i使得dist(i)<=x，则将i出队进行松弛操作。
 
SLF 和 LLF 在随机数据上表现优秀，但是在正权图上最坏情况为 O(VE)，在负权图上最坏情况为达到指数级复杂度。
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX / 2;   // 要进行两个数加法，不宜取最大值
int dis[maxn];
 
void SPFA(int n, int edge[maxn][maxn], int outset)
{
   for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[outset] = 0;      // 设置单源起点
 
    int isExist[maxn];    // 记录点是否在队列中
    memset(isExist, 0, sizeof(isExist));
    queue<int> Q;
    Q.push(outset);
    isExist[outset] = 1;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++) {
            if (edge[node][i] != inf && edge[node][i] + dis[node] < dis[i]) {
                dis[i] = edge[node][i] + dis[node];
                if (!isExist[i]) Q.push(i);
           }
        }
        isExist[node] = 0;
    }
 
    for (int i = 1; i <= n; i++) {
        cout << outset << "->" << i << ' ' << dis[i] << endl;
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
    SPFA(n, edge, 6);   // 单源起点，边集合，顶点数量
    return 0;
}
 
/*
志明与春娇
这个杀手不太冷
爱在日落浪漫时
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