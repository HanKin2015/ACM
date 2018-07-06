#include <bits/stdc++.h>
using namespace std;

int ans = 0, n;
map<string, bool> vis;

void dfs(int a[], int tag, int ret[], int tex) {
    if(tag == n) {
        bool flag = true;
        if(tex < 2) return;
        for(int i = 1; i < tex; i++) {
            if(ret[i] <= ret[i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            string str = "";
            for(int i = 0; i < tex; i++) {
                cout << ret[i] << ' ';
                str += to_string(ret[i]);
                str += '_';   //添加间隔符
            }
            cout << endl;
            if(vis[str] == false) {
                ans++;
                vis[str] = true;
            }
        }
        return;
    }
    ret[tex] = a[tag];
    dfs(a, tag + 1, ret, tex + 1);
    dfs(a, tag + 1, ret, tex);
    return;
}

int main()
{
    //int arr[15] = { 1 };  //这样只能初始化为0，其他值不行，跟memset一样
    //cout << arr[2] <<endl;
    //int num = -23;
    //string num_str = to_string(num);
    //cout << num_str << endl;

    cin >> n;
    int a[20], ret[20];
    for(int i = 0; i < n; i++) cin >> a[i];
    dfs(a, 0, ret, 0);
    cout << ans << endl;
    return 0;
}

/*
6
3 1 2 1 3 4
*/

