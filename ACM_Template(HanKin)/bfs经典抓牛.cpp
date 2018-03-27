/*
*在一个数轴上有n和k，农夫在n这个位置，奶牛在k那个位置，农夫要抓住奶牛。
*每次可以从x到x+1，或者x-1或者2*x，问最少几步可以抓到牛。
*所以可以用广搜来搜索这三个状态，直到搜索到牛所在的位置。

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
    vis[s] = 1; //改了之后记得在这里记录起点已访问
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == e) break;
        //vis[cur] = 1;  这一步你知道为啥错了不？？加入队列后就已经访问了。
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
        //先到达目的地的就是最少，如2 6，答案2
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
