#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //不超过10位，int存不下
    long long n, ans = 0;
    cin >> n;
    int arr[10], vis[10], dex = 0;
    memset(vis, 0, sizeof(vis));
    while(n) {
        arr[dex++] = n % 10;
        n /= 10;
    }
    int brr[10], tag = 0;
    for(int i = dex - 1; i >= 0; i--) {
        if(vis[arr[i]] == 0) {
            brr[tag++] = arr[i];
            vis[arr[i]] = 1;
        }
    }
    for(int i = tag - 1; i >= 0; i--) {
        ans = brr[i] + ans * 10;
    }
    cout << ans << endl;
    //仔细一想，用字符串输入比较快一些
    return 0;
}
