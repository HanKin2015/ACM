#include <iostream>
using namespace std;

void linear(int x0, int y0, int x1, int y1, int xm)
{


    double x, ym;
    double s;
    ym = y0 * ((x - x1) * 1.0 / (x0 - x1)) + y1 * ((x - x0) * 1.0 / (x1 - x0));
    s = (y1 - y0) * 1.0 / (x1 - x0);
    s = (y0 * ((xm - x1) * 1.0 / (x0 - x1)) + y1 * ((xm - x0) * 1.0 / (x1 - x0)));
    cout << int(s) << endl;
    return;
}

int main()
{
    // while(cin >> n[cnt]) cnt++;  //C语言终止符需要前面回车符，然后ctrl+z，然而C++不需要
    int n;
    int x[5] = { -170, 0, 40, 300, 550};
    int y[5] = { -1000, 700, 940, 2500, 7500};
    while(cin >> n) {
        if(n < -170) cout <<  -1000 << endl;
        else if(n > 550) cout << 7500 << endl;
        else {
            for(int i = 0; i < 4; i++) {
//                if(n == x[i]) {
//                    cout << y[i] << endl;
//                    break;
//                }
                if(n >= x[i] && n <= x[i + 1]) {
                    linear(x[i], y[i], x[i + 1], y[i + 1], n);
                    break;
                }
            }
        }
    }
    return 0;
}
