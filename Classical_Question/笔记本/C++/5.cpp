#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int N; 
    while(cin >> N){
        while(N--) {
            int a, b, c;
            cin >> a >> b >> c;
            if(a < c && b < c) cout << 0 << endl;
            else {
                if(a == c || b == c) {
                    cout << 1 << endl;
                }
                else if(a == b) cout << 0 << endl;
                else {
                    int tmp = abs(a - b);
                    if(c % tmp == 0) {
                        int ans = (c / tmp) * 2;
                        cout << ans << endl;
                    }
                    else cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}