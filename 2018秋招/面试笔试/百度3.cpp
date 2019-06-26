#include <bits/stdc++.h>
using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int maxNormalTemp(int size, int allowedChanges, string reading)
{
    // WRITE YOUR CODE HERE
    const int maxn = 1e5 + 5;
    int cnt[maxn];
    memset(cnt, 0, sizeof(cnt));
    if (reading[0] == '0') cnt[0] = 1;
    for (int i = 1; i < size; i++) {
        if (reading[i] == '0') cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = cnt[i - 1];
    }
    int maxSize = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (cnt[i] <= allowedChanges) {
            maxSize = max(maxSize, i + 1);
            continue;
        }
        for (int j = 1; j < i; j++) {
            int tmp = cnt[i] - cnt[j - 1];  // [j, i]区间内0的个数
            if (tmp <= allowedChanges) {
                maxSize = max(maxSize, i - j + 1);
                break;
            }
        }
    }
    return maxSize;
}
// FUNCTION SIGNATURE ENDS

int main()
{
    string str = "1010101";
    cout << maxNormalTemp(7, 1, str) << endl;
    return 0;
}
