#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10005
using namespace std;

LL mb;
int num, app[maxn], coin[maxn], ans[maxn], max_coin = -3213, ret[maxn], len;
void dfs(LL mb_sum, LL coin_sum, int index, int tag)
{
    if(mb_sum > mb) return;
    if(index == num) {
        if(coin_sum > max_coin) {
            for(int i = 0; i < tag; i++) ret[i] = ans[i];
            len = tag;
            max_coin = coin_sum;
        }
        return;
    }
    ans[tag] = index + 1;
    dfs(mb_sum + app[index], coin_sum + coin[index], index + 1, tag + 1);
    dfs(mb_sum, coin_sum, index + 1, tag);
    return;
}

int main()
{
    LL total = 0;
    cin >> mb;
    int cnt = 0, n;
    while(cin >> n) {
        app[cnt++] = n;
    }
    num = cnt / 2;
    bool flag = false;
    for(int i = num; i < cnt; i++) {
        total += app[i - num];
        if(app[i - num] <= mb) flag = true;
        coin[i - num] = app[i];
    }
    if(!flag) {
        cout << endl;
        return 0;
    }
    if(total <= mb) {
        for(int i = 1; i < num; i++) cout << i << ' ';
        cout << num << endl;
        return 0;
    }
    dfs(0, 0, 0, 0);
    for(int i = 0; i < len - 1; i++) cout << ret[i] << ' ';
    cout << ret[len - 1] << endl;
	return 0;
}

/*
40
12 13 23 36
11 11 20 30

880
23 36 12 13
20 34 11 11

40
20 20 20 20
20 34 11 11
*/

