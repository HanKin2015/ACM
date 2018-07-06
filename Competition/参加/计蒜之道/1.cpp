#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, a[20005], p;
    long long s, all = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        all += a[i];
    }
    cin >> p >> s;
    if(s >= (all - n) * p) {
        cout << 1 << endl;
        return 0;
    }
    sort(a, a + n);
    int cnt[20005];
    memset(cnt, 0, sizeof(cnt));
    cnt[a[0] - 1] = n;  //题目说过都会大于0
    int pre = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] != pre) {
            cnt[a[i] - 1] = n - i;
            pre = a[i];
        }
    }
    long long sum = 0;
    pre = 0;
    for(int i = 20000; i >= 0; i--) {
        if(cnt[i] != 0) pre = cnt[i];
        long long temp = sum + pre * p;
        if(temp > s) {
            cout << i + 1 << endl;
            break;
        }
        else sum = temp;
    }
    return 0;
}
