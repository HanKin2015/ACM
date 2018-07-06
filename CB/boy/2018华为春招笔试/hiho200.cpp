/*
*开始的思路(遍历一遍做异或判断)有个致命错误，如1 3 2 2，答案应该是0
*只需要统计偶数和奇数之差即可
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, arr, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr;
        if(arr & 1) cnt++;
    }
    cout << abs(n - cnt - cnt) << endl;
    return 0;
}
