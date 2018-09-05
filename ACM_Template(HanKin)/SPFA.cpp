/*
����⣬��Ҫ�����·���㷨����С�������㷨�����ˡ�������
 
�� Bellman-Ford�㷨 �Ķ����Ż��㷨�ı��
�����󺬸�Ȩ�ߵĵ�Դ���·�����Լ��и�Ȩ��
�����¸��ӶȺ����� Bellman-Ford ��ͬ��Ϊ O(VE)
Ϊ�˱��������ĳ��֣�����Ȩͼ��Ӧʹ��Ч�ʸ��ߵ�Dijkstra�㷨��
 
������-����(Bellman-Ford)�㷨
��ԭ��Ϊ���������ɳڣ���ÿ���ɳ�ʱ��ÿ���߶�����һ��
����n-1���ɳں��ܸ��£���˵��ͼ���и���������޷��ó��������������
Dijkstra�㷨�޷��жϺ���Ȩ�ߵ�ͼ�����·��
���������Ȩ����û�и�Ȩ��·����·��Ȩֵ��Ϊ���������и�Ȩ�ıߣ�����ʱ��\
Ҳ���Բ���Bellman - Ford�㷨��ȷ������·����
 
��̬�ƽ���
����һ���Ƚ��ȳ��Ķ�������������Ż��Ľ�㣬�Ż�ʱÿ��ȡ�����׽��u��\
������u�㵱ǰ�����·������ֵ���뿪u����ָ��Ľ��v�����ɳڲ�����\
���v������·������ֵ������������v�㲻�ڵ�ǰ�Ķ����У��ͽ�v������β��\
�������ϴӶ�����ȡ������������ɳڲ�����ֱ�����п�Ϊֹ��
 
һ����ֱ�۵�����������Ȩͼ��BFSת��������
 
SPFA�㷨�������Ż�����SLF��LLL
SLF��Small Label First ���ԣ���Ҫ����Ľڵ���j������Ԫ��Ϊi����dist(j)<dist(i)����j������ף���������β��
LLL��Large Label Last ���ԣ������Ԫ��Ϊi������������distֵ��ƽ��ֵΪx����dist(i)>x��i���뵽��β��\
������һԪ�أ�ֱ���ҵ�ĳһiʹ��dist(i)<=x����i���ӽ����ɳڲ�����
 
SLF �� LLF ����������ϱ������㣬��������Ȩͼ������Ϊ O(VE)���ڸ�Ȩͼ������Ϊ�ﵽָ�������Ӷȡ�
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX / 2;   // Ҫ�����������ӷ�������ȡ���ֵ
int dis[maxn];
 
void SPFA(int n, int edge[maxn][maxn], int outset)
{
   for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[outset] = 0;      // ���õ�Դ���
 
    int isExist[maxn];    // ��¼���Ƿ��ڶ�����
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
    SPFA(n, edge, 6);   // ��Դ��㣬�߼��ϣ���������
    return 0;
}
 
/*
־���봺��
���ɱ�ֲ�̫��
������������ʱ
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