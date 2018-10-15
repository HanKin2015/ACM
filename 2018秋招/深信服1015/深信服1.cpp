#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int arr[maxn] = {0};
        arr[1] = a;
        arr[2] = b;
        arr[3] = c;
        for (int i = 4; i < 10000; i++) {
            int tmp = arr[i - 1] + arr[i - 2] + arr[i - 3];
            if (tmp >= 10) {
                arr[i] = tmp / 10;
                arr[++i] = tmp % 10;
            }
            else arr[i] = tmp;
        }
        if (n < 10000) {
            cout << arr[n] << endl;
            continue;
        }
        // Ñ°ÕÒÑ­»·½Ú
        int s, e;
        for (int i = 1; i < 10; i++) {
            bool flag1 = false;
            for (int j = i + 1; j < 500; j++) {
                bool flag2 = true;
                for (int k = 0; k < 10; k++) {
                    if (arr[i + k] != arr[j + k]) {
                        flag2 = false;
                        break;
                    }
                }
                if (flag2) {
                    s = i;
                    e = j;
                    flag1 = true;
                    break;
                }
            }
            if (flag1) break;
        }
        //cout << s << ' ' << e << endl;
        int mod = e - s;
        if (n > s) {
            n -= s;
            n = s + n % mod;
        }
        cout << arr[n] << endl;
    }
    return 0;
}

