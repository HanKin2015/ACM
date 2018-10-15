#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, n;
        //cin >> a >> b >> c >> n;
        for (int x = 0; x < T; x++) {
            for (int y = 0; y < T; y++) {
                for (int z = 0; z < T; z++) {


        int arr[maxn] = {0};
        arr[1] = x;
        arr[2] = y;
        arr[3] = z;
        for (int i = 4; i < 100; i++) {
            int tmp = arr[i - 1] + arr[i - 2] + arr[i - 3];
            if (tmp >= 10) {
                arr[i] = tmp / 10;
                arr[++i] = tmp % 10;
            }
            else arr[i] = tmp;
        }
        for (int i = 1; i < 100; i++) cout << arr[i];
        cout << endl;
                        }
            }
        }
    }
    return 0;
}

