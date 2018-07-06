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
    int n, k;
    cin >> n >> k;
    while(k--) {
        if(n % 10 != 0) n--;
        else n /= 10;
    }
    cout << n << endl;
    return 0;
}
