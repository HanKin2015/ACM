#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    double sum1 = 0, sum2 = 0;
    int value, flag;
    for(int i = 0; i < n; i++) {
        cin >> value >> flag;
        sum1 += value;                       // ��Ʒ�ܼ�
        if(flag == 1) sum2 += value * 0.8;   // ֻ���ܰ����Ż�
        else sum2 += value;
    }
    double ans = sum1;
    for(int i = 0; i < m; i++) {
        cin >> value >> flag;   // ����ÿ���Żݺ�ļ۸�
        if(sum1 >= value) {
            if(ans > sum1 - flag) ans = sum1 - flag;
        }
    }
    if(ans > sum2) ans = sum2;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
