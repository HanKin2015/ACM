/*
ͨ���޲κ���pass��Ȼ��ڶ������x��ֵΪ456��
*/
#include <bits/stdc++.h>
using namespace std;

void pass(int n)
{
    //cout << 456 << endl;
    //exit(0);
    int temp;
    //cout << &temp << endl;
    int *p = &temp;
    *(p + n) = 456;
    return;
}

int main()
{
    int x = 123;
    //cout << &x << endl;
    cout << x << endl;
    for (int i = -100; i < 100; i++) {   // ���˲��������㣬��Ϊ���������˶��int����
        pass(i);
        cout << i << ' ' << x << endl;
        if (x == 456) break;
    }
    return 0;
}

/* ���������еĵ���
//ͨ���޲κ���pass��Ȼ��ڶ������x��ֵΪ456��
#include <bits/stdc++.h>
using namespace std;

void pass()
{
    int temp;
    int *p = &temp;
    cout << (p + 13) << endl;
    *(p + 13) = 456;
    return;
}

int main()
{
    int x = 123;
    //cout << &x << endl;
    cout << x << endl;
    pass();
    cout << x << endl;
    return 0;
}
*/
