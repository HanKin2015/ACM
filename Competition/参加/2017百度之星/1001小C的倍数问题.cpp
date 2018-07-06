#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define LL long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int P;
        cin >> P;
        int cnt = 0, tmp = sqrt(P - 1);
        for(int i = 1; i < tmp; i++) {
            if((P - 1) % i == 0) cnt += 2;
        }
        if(tmp * tmp == (P - 1)) cnt++;
        cout << cnt << endl;
    }
    //if(sqrt(6) * sqrt(6) == 6) cout << "6666666" << endl; //Ò×´íµã
    return 0;
}

