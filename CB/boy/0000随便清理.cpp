#include <bits/stdc++.h>
using namespace std;

//��������ȷʵ�Ứ��ʱ��
void fun1(vector<int> v1, vector<int> v2, vector<int> v3)
{
    //int cnt = 0;
    //for(int i = 0; i < 10000000; i++) cnt++;
    return;
}

//��������ȷʵ�Ứ��ʱ��
void fun2(vector<int> v1, vector<int> v2, vector<int> v3)
{
    for(int i = 0; i < v1.size(); i++) {
        v1.pop_back();
        v2.pop_back();
        v3.pop_back();
    }
    return;
}

//ȫ�ֱ����ܽ�ʡʱ��
vector<int> vv1, vv2, vv3;
void fun3()
{
    for(int i = 0; i < vv1.size(); i++) {
        vv1.pop_back();
        vv2.pop_back();
        vv3.pop_back();
    }
    return;
}

//�������ݵ�ַ
void fun4(vector<int>::iterator v1, vector<int>::iterator v2, vector<int>::iterator v3, int len)
{
    //�Ǹ�������뷨
    return;
}

int main()
{

    vector<int> v;
    for(int i = 0; i < 10000000; i++) {
        v.push_back(i);
        vv1.push_back(i);
        vv2.push_back(i);
        vv3.push_back(i);
    }
    clock_t tim = clock();
    fun1(v, v, v);
    cout << "�������ݵ�ʱ��fun1 = " << clock() - tim << endl; //45-48

    tim = clock();
    fun2(v, v, v);
    cout << "�������ݺͼ����ʱ��fun2 = " << clock() - tim << endl; //1665-1726

    tim = clock();
    fun3();
    cout << "�����ʱ��fun3 = " << clock() - tim << endl; //1605-1705
    return 0;
}
