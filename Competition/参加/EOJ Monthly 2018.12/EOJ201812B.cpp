#include <bits/stdc++.h>
using namespace std;

int main()
{
    int seed = time(0);
    srand(seed);
    int n;
    const double eps = 1e-3;
    cin >> n;
    if (n > 900) {
        cout << 0 << endl;
        return 0;
    }

    double sumDis = 0;
    int cnt = 1e8 / (n * n);
    for (int i = 0; i < cnt; i++) {
        double x[1005], y[1005];
        for (int j = 0; j < n; j++) {
            x[j] = rand() / (RAND_MAX + 1.0);;
            y[j] = rand() / (RAND_MAX + 1.0);;
            //cout << x[j] << endl;
        }
        double minDis = 100;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double dis = sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]));
                if (dis < minDis) minDis = dis;
            }
        }
        sumDis += minDis;
    }
    sumDis /= cnt;
    cout << sumDis << endl;
    return 0;
}

