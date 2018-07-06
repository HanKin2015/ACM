#include <bits/stdc++.h>
using namespace std;

char ball[5] = {'A', 'B', 'C', 'D', 'E'};
int ans = 0;
int flag = 0;
void dfs(int cnt, char ret[], int dex)
{
    if(cnt == 5) {
        if(ret[dex - 1] == 'A') {
            ans++;
            if(flag < 5) {
                for(int i = 1; i < dex; i++) {
                    cout << ret[i] << ' ';
                }
                cout << endl;
                flag++;
            }
        }
        return;
    }
    ret[dex] = 'A';  //ÏÂÒ»¸öÇò
    if(ret[dex - 1] != 'A' && ret[dex - 1] != 'B' && ret[dex - 1] != 'C') dfs(cnt + 1, ret, dex + 1);
    ret[dex] = 'B';
    if(ret[dex - 1] != 'B' && ret[dex - 1] != 'A' && ret[dex - 1] != 'C') dfs(cnt + 1, ret, dex + 1);
    ret[dex] = 'C';
    if(ret[dex - 1] != 'C' && ret[dex - 1] != 'E') dfs(cnt + 1, ret, dex + 1);
    ret[dex] = 'D';
    if(ret[dex - 1] != 'D') dfs(cnt + 1, ret, dex + 1);
    ret[dex] = 'E';
    if(ret[dex - 1] != 'E' && ret[dex - 1] != 'C') dfs(cnt + 1, ret, dex + 1);

    /*
    if(ret[dex - 1] == 'A') {
        ret[dex] = 'C';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'D';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'E';
        dfs(cnt + 1, ret, dex + 1);
    }
    if(ret[dex - 1] == 'B') {
        ret[dex] = 'C';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'D';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'E';
        dfs(cnt + 1, ret, dex + 1);
    }
    if(ret[dex - 1] == 'C') {
        ret[dex] = 'D';
        dfs(cnt + 1, ret, dex + 1);
    }
    if(ret[dex - 1] == 'D') {
        ret[dex] = 'A';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'B';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'C';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'E';
        dfs(cnt + 1, ret, dex + 1);
    }
    if(ret[dex - 1] == 'E') {
        ret[dex] = 'A';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'B';
        dfs(cnt + 1, ret, dex + 1);
        ret[dex] = 'D';
        dfs(cnt + 1, ret, dex + 1);
    }
    */
    return;
}

int main()
{
    char ret[10];
    ret[1] = 'A';
    dfs(0, ret, 2);
    cout << ans << endl;
    return 0;
}
