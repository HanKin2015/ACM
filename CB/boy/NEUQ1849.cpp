#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T, N, B;
    cin >> T;
    while(T--) {
        cin >> N >> B;
        int temp, sum = 0, money[1005];
        for(int i = 0; i < N; i++) {
            cin >> temp;
            sum += temp;
        }
        for(int i = 0; i < B; i++) {
            cin >> money[i];
        }
        sort(money, money + B);
        int ans = 0;
        for(int i = 0; i < N && i < B; i++) {
            if(sum - money[i] >= 0) {
                ans++;
                sum -= money[i];
            }
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}
