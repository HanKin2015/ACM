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
	cout << ans << endl;
	return 0;
}

