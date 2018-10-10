#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, n, a[1000005];
    cin >> N;
    while(N--) {
        cin >> n; //n is not 1
        int cnt = 1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int dex = n - 2;
        int tmp = a[n - 1] - a[dex];
        bool flag = true;
        while(flag) {
            for(int i = dex - 1; i >= 0; i--) {
                int  temp = a[i + 1] - a[i];
                if(temp < a[0]) break;
                if(temp != tmp) {
                    dex--;
                    flag = false;
                    tmp = a[n - 1] - a[dex];
                    break;
                }
            }
            if(flag) {
                break;
            }
            else flag = true;
        }
        cout << tmp << endl;
    }
    return 0;
}