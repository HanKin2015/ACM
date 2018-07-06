#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

struct opt{
    int l, r;
    bool flag = false;
}opt[1005];

int elem[1005];
int pos[1005];
int pre[1005];

LL N, M;
LL maxn = 99999999999;
LL ans = maxn;
LL SUM(int l, int r)
{
    LL sum = 0;
    for(int i = l; i <= r; i++) {
        sum += elem[pos[i]];
        if(opt[pos[i]].flag == true) {
            int t = 0;
            for(int j = 1; j <= N; j++) {
                if(pos[j] == i) {
                    t = j;
                    break;
                }
            }

            if(t && opt[pos[i]].l <= t && opt[pos[i]].r >= t) continue;
            sum += SUM(opt[i].l, opt[i].r);
        }
    }
    return sum;
}

int main()
{
    memset(pre, 0, sizeof(pre));
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> M;
        elem[i] = M;   //污染值
        pos[i] = i;    //元素号
    }
    cin >> M;
    int tz, x, l, r, y, num[100005], dex = 0;
    int cnt = N;  //书(元素)的个数，会自动增加
    while(cin >> tz) {
        num[dex++] = tz;
    }
    for(int i = 0; i < dex; i++) {
        if(num[i] == 1) {
            opt[num[i + 1]].flag = true;
            opt[num[i + 1]].l = num[i + 2];
            opt[num[i + 1]].r = num[i + 3];
            i += 3;
        }
        else {
            cnt++;
            pre[cnt] = pos[num[i + 1]];
            pos[num[i + 1]] = cnt;
            i += 2;
        }
    }

    for(int i = 1; i <= cnt; i++) {
        LL sum = 0;
        sum += elem[i];
        if(opt[i].flag == true) {
            int t = 0;
            for(int j = 1; j <= N; j++) {
                if(pos[j] == i) {
                    t = j;
                    break;
                }
            }

            if(t && opt[pos[i]].l <= t && opt[pos[i]].r >= t) continue;
            sum += SUM(opt[i].l, opt[i].r);
        }
        if(pre[i] != 0) {
            sum += elem[pre[i]];
        if(opt[pre[i]].flag == true) {
            int t = 0;
            for(int j = 1; j <= N; j++) {
                if(pos[j] == i) {
                    t = j;
                    break;
                }
            }

            if(t && opt[pos[pre[i]]].l <= t && opt[pos[pre[i]]].r >= t) continue;
            sum += SUM(opt[pre[i]].l, opt[pre[i]].r);
        }
        }
        if(sum && sum < ans) ans = sum;
    }
    cout << ans << endl;
    return 0;
}
