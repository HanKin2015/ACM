/*
*��ʼ��˼·(����һ��������ж�)�и�����������1 3 2 2����Ӧ����0
*ֻ��Ҫͳ��ż��������֮���
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
