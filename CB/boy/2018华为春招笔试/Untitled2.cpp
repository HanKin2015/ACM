/*
*输入：6 8 2 11 6 4 5 123456789101112 2 6
*输出：2 2 4 5 6 6 6 8 11 123456789101112
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n[1005], cnt = 0;
    while(cin >> n[cnt]) cnt++;  //C语言终止符需要前面回车符，然后ctrl+z，然而C++不需要
    sort(n, n+ cnt);
    for(int i = 0; i < cnt; i++) cout << n[i] << ' ';
    return 0;
}
