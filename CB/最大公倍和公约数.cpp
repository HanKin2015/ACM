#include<bits/stdc++.h> // ����ͷ�ļ�
#include <iostream>
using namespace std;

// ŷ������㷨-շת�����
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    // a*b�ٳ������Լ��������С������
    int a = 96, b = 54;
    int gcd1 = gcd(a, b);
    int gcd2 = __gcd(a, b); // ���Ǳ�׼�⺯��
    int lcm = a / gcd1 * b; // �ȳ���˷�ֹ���
    cout << gcd1 << endl;
    cout << gcd2 << endl;
    cout << lcm << endl;
    return 0;
}
