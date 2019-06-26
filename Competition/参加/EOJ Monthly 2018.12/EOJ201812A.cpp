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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LL N, A, B;
    cin >> N >> A >> B;
    LL maxSum = B * (N - 1) + A;
    LL minSum = A * (N - 1) + B;
    cout << maxSum - minSum + 1 << endl;
	return 0;
}
