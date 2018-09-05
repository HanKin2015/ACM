/*
1����ʼ��(�ڽӾ���洢,���ɴ�Ϊ�����,�������Ϊ0)
2�����嵥Դ���
3������n��:
           ����ǰһ�㵽�����е�ľ���(ǰһ���ǵ�Դ�������̵�)
           ѡȡ���е�ľ�������Сֵ(��ǰһ������ѷ��ʱ��)
 
 
�ֽеҿ�˹�����㷨
���㷨���Ӷ�Ϊn^2,�������ԶС��n^2,�Դ˿��Կ����ö��������ݽṹ�����Ż�
ȡ�����·���ĸ��ӶȽ�ΪO(1)��ÿ�ε����ĸ��ӶȽ�ΪO��elogn����eΪ�õ�ı���
���Ը��ӶȽ�ΪO((m+n)logn)
��Դ���·������
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e2 + 5;
const int inf = INT_MAX;
int dis[maxn]; // ��¼��̾����С
 
 
// ʹ���˹���������������Ȩ����ͼ��������ͼ�ĵ�Դ���·������
void Dijkstra(int n, int edge[maxn][maxn], int outset)
{
    // ��¼���Ѿ�������ѡ������ѡ���һ������̵ģ����治���ٴθ���
    bool vis[maxn];
    memset(vis, 0, sizeof(vis));
 
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[outset] = 0;    // ���õ�Դ��㣬������n2���Ӷȣ������Դ��n3���Ӷȡ�
 
    int preNode = outset, path[maxn];     // ��¼ÿ�����ǰһ����(Ψһ),��������Դ�ӡ·��
    int select[maxn];   // ��¼ÿ��ѡ�����̵�
    for (int cnt = 1; cnt <= n; cnt++) {     // n�������Ҫ����n��
        int minNode = outset, minDis = inf;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] < minDis) {  // ѡ��ǰһ���㵽���е�ı������
                minDis = dis[i];
                minNode = i;
            }
        }
        while (edge[preNode][minNode] == inf) preNode = path[preNode]; // ����
        path[minNode] = preNode;
        preNode = minNode;
        vis[minNode] = 1;
        select[cnt] = minNode;
        for (int i = 1; i <= n; i++) {       // ���µ���ÿ�������̾���
            //��δ���ʣ�ǰһ����͵�ǰ��֮���бߣ������������
            if (!vis[i] && edge[minNode][i] != inf && dis[minNode] + edge[minNode][i] < dis[i]) {
                dis[i] = dis[minNode] + edge[minNode][i];
            }
 
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << select[i] << ' ' << dis[select[i]] << endl;
        // �����ӡ·��
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
    Dijkstra(n, edge, 6);   // �����������߼��ϣ���Դ���
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