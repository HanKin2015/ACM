/*
*��һ����������n��k��ũ����n���λ�ã���ţ��k�Ǹ�λ�ã�ũ��Ҫץס��ţ��
*ÿ�ο��Դ�x��x+1������x-1����2*x�������ټ�������ץ��ţ��
*���Կ����ù���������������״̬��ֱ��������ţ���ڵ�λ�á�

5 17

4
*/

#include <iostream>
#include <queue>
#include <cstring>
#define maxn 100005
using namespace std;

int bfs(int s, int e)
{
    int vis[maxn], step[maxn];
    memset(vis, 0, sizeof(vis));
    step[s] = 0;
    vis[s] = 1; //����֮��ǵ��������¼����ѷ���
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == e) break;
        //vis[cur] = 1;  ��һ����֪��Ϊɶ���˲�����������к���Ѿ������ˡ�
        if(cur + 1 < maxn && !vis[cur + 1]) {
            step[cur + 1] = step[cur] + 1;
            Q.push(cur + 1);
            vis[cur + 1] = 1;
        }
        if(cur - 1 > 0 && !vis[cur - 1]) {
            step[cur - 1] = step[cur] + 1;
            Q.push(cur - 1);
            vis[cur - 1] = 1;
        }
        if(cur * 2 < maxn && !vis[cur * 2]) {
            step[cur * 2] = step[cur] + 1;
            Q.push(cur * 2);
            vis[cur * 2] = 1;
        }
        //�ȵ���Ŀ�ĵصľ������٣���2 6����2
    }
    return step[e];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}
