#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //������10λ��int�治��
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
    //��ϸһ�룬���ַ�������ȽϿ�һЩ
    return 0;
}
