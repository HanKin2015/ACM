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
    /*´ò±í
    LL pre = 0;
    for(int i = 1; i <= 13; i++) {
        int n = i, len = 0;
        while(n) n /= 10, len++;
        LL num = pre * pow(10, len) + i + 0.5;
        cout << num << ' ';
        if(num % 3 == 0) cout << "yes" << endl;
        else cout << "no" << endl;
        pre = num;
    }
    */
    int l, r;
    while(cin >> l >> r) {
        int ans = r * 2 / 3 - ((l - 1) * 2 / 3);
        cout << ans << endl;
    }
	return 0;
}
