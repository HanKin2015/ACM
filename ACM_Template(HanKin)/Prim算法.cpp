/*
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
const int inf = INT_MAX;
 
void Prim(int outset, int edge[maxn][maxn])
{
    int minDis[maxn];     // ��¼�㵽��С����������̾���
    for (int i = 1; i <= V; i++) minDis[i] = edge[outset][i];
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    vis[outset] = 1;
 
    for (int i = 0; i < V - 1; i++) {  // ��ҪѰ��V - 1����
int min = Integer.MAX_VALUE;
            //ѡ��ʣ�¶��㵽����������С��
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
            //������k������������������ʣ�¶��㵽������������С��
            for(int m=0;m<nVerts;m++)
            {
                //���ʣ�ඥ�㵽k����������������С��С�ڲ���ǰ������������С��
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
    Floyd(n, edge);   // ��Դ��㣬�߼��ϣ���������
    return 0;
}