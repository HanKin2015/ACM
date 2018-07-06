#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 300005
using namespace std;

int main()
{
    int n, w, num;
    long long sum = 0, MAX = 0, MIN = 0;
    bool flag = true;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        if(sum > w) flag = false;
        if(sum > MAX) MAX = sum;
        if(sum < MIN) MIN = sum;
    }
    if(!flag) cout << 0 << endl;
    else {
        int ans = w - MAX + MIN + 1;
        if(ans < 0) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
