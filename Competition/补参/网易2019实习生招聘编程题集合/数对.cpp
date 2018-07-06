/*
举个例子，假设 k=3,n=11
因为要求对y取余>=k 所以y从k+1开始 （如果y=k，那么取余最大才是k-1）
对于第一个y=4,来求有多少个x满足条件
      y       y        y
1 2 3 4 5 6 7 8 9 10 11
所以n被分成了两部分，一部分是1-(n/y)*y:1-8  另一部分：9-11 没被整除的部分
1-4 5-8 每一部分都有 （y-k)个取余>=k的数
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define LL long long
#define maxn 10005
using namespace std;

int main()
{
    LL n, k, ans = 0; cin >> n >> k;
    /*for(int i = 1; i <= n; i++) {
        for(int j = k + 1; j <= n; j++) {
            if(i % j >= k) ans++;
        }
    }*/
    for(int i = k + 1; i <= n; i++) {
        ans += (n / i) * (i - k) + max(n % i - k + 1, 0LL);
    }
    if(k == 0) cout << n * n << endl;
    else cout << ans << endl;
	return 0;
}
