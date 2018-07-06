#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10000005
using namespace std;

int main()
{
    LL n; cin >> n;
    if(n < 25) {
        cout << -1 << endl;
        return 0;
    }
    int a[20], b[20], dex = 0;
    while(n) {
        a[dex] = n % 10;
        b[dex++] = n % 10;
        n /= 10;
    }
    //have four solutions 00,25,50,75
    bool f1 = false, f2 = false;
    int ans1 = 0, ans2 = 0;
    bool flag1 = false, flag2 = false;

    //if here is qiandao 0,final do swap
    //first is 00,50
    for(int i = 0; i < dex; i++) {
        if(a[i] == 0 && !flag1) {
            flag1 = true;
            for(int j = i; j > 0; j--) {
                swap(a[j], a[j - 1]);
                ans1++;
            }
            i = 0;
        }
        else if(flag1 && (a[i] == 0 || a[i] == 5)) {
            ans1 += i - 1;
            f1 = true;   //have answer
            break;
        }
    }

    //second is 25,75
    for(int i = 0; i < dex; i++) {
        if(b[i] == 5 && !flag2) {
            flag2 = true;
            for(int j = i; j > 0; j--) {
                swap(b[j], b[j - 1]);
                ans2++;
            }
            i = 0;
        }
        else if(flag2 && (b[i] == 2 || b[i] == 7)) {
            ans2 += i - 1;
            f2 = true;  //have answer
            break;
        }
    }
    for(int i = dex - 1; i >= 0; i--) {
        if(a[i] != 0) {
            ans1 += dex - 1 - i;
            break;
        }
    }
    for(int i = dex - 1; i >= 0; i--) {
        if(b[i] != 0) {
            ans2 += dex - 1 - i;
            break;
        }
    }

    int ans = maxn;
    if(f1) ans = min(ans1, ans);
    if(f2) ans = min(ans2, ans);
    if(ans == maxn) cout << -1 << endl;
    else cout << ans << endl;
	return 0;
}
