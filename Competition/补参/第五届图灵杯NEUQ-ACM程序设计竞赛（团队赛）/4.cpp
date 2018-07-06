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

int main()
{
    int n;
    char str[maxn];
    cin >> n;
    cin >> str;
    int ans = 0;
    for(int i = 2; i < n; i++) {
        if(str[i] == '6' && str[i - 1] == '6' && str[i - 2] == '6') ans++;
    }
    cout << ans << endl;
    return 0;
}
