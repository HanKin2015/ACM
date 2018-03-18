#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    int cnt = N / 10;
    ans = ans + (cnt / 5) * 7;
    cnt = cnt % 5;
    ans = ans + (cnt / 3) * 4;
    ans = ans + cnt % 3;
    cout << ans << endl;
    return 0;
}
