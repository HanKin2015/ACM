#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for(int i = 2; i < 1000; i++) {
        int n = i, sum = 0;
        while(n) {
            //sum += pow(n % 10, 3);
            int tmp = n % 10;
            sum += tmp * tmp * tmp;
            n /= 10;
        }
        if(sum == i) cout << i << "  ";
    }
    cout << endl;
    int tmp = pow(5, 3);
    cout << tmp << endl;
    cout << pow(5, 3) << endl;
    double t = pow(5, 3);
    cout << t << endl;
    return 0;
}
