/*
*判断两个矩形重叠函数正确
*如果两个矩形重叠则各加1错误，如a交b，b交c，但a不交c，答案就会出现3，正确是2。

看n的范围就能知道这道题可以支持几乎所有的多项式复杂度的算法了，我的算法是O(n^3)的复杂度。
其实可以做到O(n^2logn)，但是要用到线段树，对于n<=50的规模来说可能会因为常数大程序反而跑得更慢。
首先因为坐标的范围是1e9，因此第一步肯定是对坐标进行离散化，我们存下所有的x坐标和y坐标，
然后分别进行排序。然后我们得到了两个数组，一个是x坐标的数组，一个是y坐标的数组，分别都有2n个整数，
这2个数组把平面分成了(2n-1)*(2n-1)个格子。所有的初始矩形都由这些格子组成。我们可以取这些格子的对
角线中点(共(2n-1)(2n-1)个)代表这些格子，然后考虑这些这些点分别包含在多少个矩形中。然后求出被覆盖
最多次的格子就是答案了。
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#define LL long long
#define maxn 10005
using namespace std;

struct rectangle {
    int l1, l2, r1, r2;
    //int cnt = 1;
};

bool check(rectangle a, rectangle b) {
    return !(a.r1 <= b.l1 || a.r2 <= b.l2 || b.r1 <= a.l1 || b.r2 <= a.l2);
}

int main()
{
    //cout << 0LL << endl;
	int n; cin >> n;
	rectangle rec[55];
	vector<int> x, y;
    for(int i = 0; i < n; i++) cin >> rec[i].l1, x.push_back(rec[i].l1);
    for(int i = 0; i < n; i++) cin >> rec[i].l2, y.push_back(rec[i].l2);
    for(int i = 0; i < n; i++) cin >> rec[i].r1, x.push_back(rec[i].r1);
    for(int i = 0; i < n; i++) cin >> rec[i].r2, y.push_back(rec[i].r2);
	int ans = 1;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * n; j++) {
            int temp = 0;
            for(int k = 0; k < n; k++) {
                if(rec[k].l1 <= x[i] && rec[k].l2 <= y[j] && rec[k].r1 > x[i] && rec[k].r2 > y[j]) temp++;
            }
            ans = max(ans, temp);
        }
	}
	/*
	printf("(%d, %d) (%d, %d)\n\n", rec[33].l1, rec[33].l2, rec[33].r1, rec[33].r2);
	for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(check(rec[i], rec[j])) {
                if(i == 33) {
                    printf("(%d, %d) (%d, %d)\n", rec[j].l1, rec[j].l2, rec[j].r1, rec[j].r2);
                }
                if(j == 33) {
                    printf("(%d, %d) (%d, %d)\n", rec[i].l1, rec[i].l2, rec[i].r1, rec[i].r2);
                }
                rec[i].cnt++;
                rec[j].cnt++;
                ans = max(ans, rec[i].cnt);
                ans = max(ans, rec[j].cnt);
            }
        }
	}
	for(int i = 0; i < n; i++) if(rec[i].cnt == ans) cout << i << endl;
    */
	cout << ans << endl;
	return 0;
}
