/*
...| F | G | F | G |...������GΪD-F����Ų��ڷ�϶�ϵ�����Ϊa*(F+G) < b*L < a*(F+G)+F
�����������ʽ��0 < b*L - a * D < F�������Ƿ��������a, bʹ��b*L - a*D�Ĳ���С�Ҵ���0��
b*L - a*D�Ĵ���0����С��ֵ��ʵ���ǵ���gcd(L, D)������gcd(L, D) < F���ǽŲ��ڷ�϶�ϵ�������
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T, F, L, D;
    cin >> T;
    while (T--) {
        cin >> L >> F >> D;
        int G = gcd(L, D);
        if (F > G) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
