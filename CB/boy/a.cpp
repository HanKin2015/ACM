#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    double price = 10000;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a * 1.0 / b < price) price = a * 1.0 / b;
    }
    price = price * m;
    cout << setprecision(8) << price << endl;
    return 0;
}
