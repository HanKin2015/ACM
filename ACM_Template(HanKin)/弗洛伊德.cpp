/*
1����ʼ��(�ڽӾ���洢,���ɴ�Ϊ�����,�������Ϊ0)
2������forѭ��:ö�پ���㣬�յ㣬�м��
�Ƕ�̬�滮��һ�����ӣ�״̬ת�Ʒ��̣�map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
 
 
Floyd-Warshall�㷨�����㷨Ҳ��ΪFloyd�㷨��Roy-Warshall�㷨��Roy-Floyd�㷨��WFI�㷨��
�����ɳڼ������ɳڲ�����������i��j֮����������������һ���ɳ�
ʱ�临�Ӷ�O(n^3)�ռ临�Ӷ�O(n^2)
���Դ���·�����󴫵ݱհ�
�Ƕ�̬�滮��һ�����ӣ�״̬ת�Ʒ��̣�map[i,j]=min{map[i,k]+map[k,j],map[i,j]}
�ɳڲ���(relaxation)��ָ����ÿ������v��V��������һ������d[v]������������Դ��s��v�����·����Ȩֵ���Ͻ磬��Ϊ���·�����ƣ�shortest-path estimate����
 
���Ժ͵Ͻ�˹������һ���ĸ��Ӷ�(��Դ)???
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX / 2;   // Ҫ���мӷ�������ȡ���ֵ
 
void Floyd(int n, int dis[maxn][maxn])
{
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            for (int k = 1; k <= n; k++) {
               dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
 
    // ��Դ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << "->" << j << ' ' << dis[i][j] << endl;
        }
   }
 
    // ��Դ
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
    Floyd(n, edge);   // ��Դ��㣬�߼��ϣ���������
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