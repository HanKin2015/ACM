#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int X, Y, Z, temp;
    cin >> X >> Y >> Z;
    if(X < Y) temp = X, X = Y, Y = temp;
    if(Y < Z) temp = Y, Y = Z, Z = temp; //确定Z为最小
    if(X < Y) temp = X, X = Y, Y = temp;
    int ans;
    if(X <= Y + Z) ans = ceil((X+Y+Z) / 20.0) * 6;
    else {
        ans = (Y + Z) / 10;
        int K = (Y + Z) % 10;
        X = X - ans * 10;
        if(K < 8) {
            ans++;
            X = X - (15 - K);
        }
        else {
            ans++;
            X -= K;
        }
        ans += ceil(X / 15.0);
        ans *= 6;
    }
    cout << ans << endl;
    return 0;
}
