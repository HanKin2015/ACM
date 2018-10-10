#include <bits/stdc++.h>
using namespace std;

作者：猩猩舞剑
链接：https://www.nowcoder.com/discuss/80836?type=0&order=0&pos=6&page=1
来源：牛客网

第一题：单引号、双引号、转移符\  搞一搞就过了。
第二题：hash，0%，应该是因为utf-8中文编码的原因，反正我对各种编码一直很头疼。。
第三题：LA3882 约瑟夫变形的变形。。。10^7数据范围，目测方法跟LA3882差不多，DFS写怕爆栈，又怕超时，反正实习找到了，感觉过的概率不大不搞了。
第四题、第五题没看。。
int main()
{
    int N, n, m, arr[1005];
    cin >> N;
    while(N--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        int cnt = 0, vis[100005], tag = 0;
        for(int i = 0; i < 100005; i++) vis[i] = 1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] != 0) count++;
            if(vis[i] !=0 && count % arr[tag] == 0) {
                vis[i] = 0;
                cnt++;
                tag = (tag + 1) % m;
                count = 0;
                //cout << i << ' ';
            }
            if(i == n - 1) i = -1;
            if(cnt == n - 1) break;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] != 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

/*
3 1  //5
1 1  //9
2 2  //4
2 1  //6

3 1
0 1 2 3 4 5 6 7 8 9
0 1     4 5     8 9
        4 5        
          5
1 1
2 2

0  3 6 9  4  6  8
0  4 8
4 
2 1
0  3 6 9
6
*/
