/*
author: HanKin
date: 2018/03/21
content: �̳С���̬����װ���麯����˽�й��б�����Ա����Ԫ���������ء���д
ö�١�typedef��define������ռ���ַ���ֵ��Χ
Lambda������extern
*/

#include <bits/stdc++.h>
using namespace std;

class profession {

};

class student {

public:
private:
protected:

};

enum time {
    first,second,
    third,forth,fifth
};

int vbr;

int main()
{
    cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
    cout << "\t���ֵ��" << (numeric_limits<double>::max)();
    cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;
    double n = 1e256;
    double m = 172189378912739871237129273891739812;
    cout << n << endl;
    cout << m << endl;

    enum time a = fifth;
    if (a == fifth) {
        cout << a << endl;
    }

    // ���ֲ�����������ʱ��ϵͳ��������ʼ�������������ж����ʼ��������ȫ�ֱ���ʱ��ϵͳ���Զ���ʼ��
    int var;
    cout << var << endl;
    cout << vbr << endl;
    return 0;
}
