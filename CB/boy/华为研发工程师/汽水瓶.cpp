/*
递归问题
3个瓶子换1瓶水+1个空瓶子，两个瓶子换1瓶水+0个空瓶子，1个瓶子换0瓶水。

通过数学分析，最后获得的饮料数是总空瓶数整除2 。
*/
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

int f(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return f(n-2)+1;
}

int main()
{
    int n;
    while(cin >> n) {
        if(n == 0) break;
        int ans = 0;
        while(n >= 3) {
            ans += n / 3;
            n = n / 3 + n % 3;
        }
        if(n == 2) ans++;
        cout << ans << endl;
    }
	return 0;
}
