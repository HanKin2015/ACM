#include <bits/stdc++.h>
#define LL long long
#define maxn 30000005
using namespace std;

vector<int> v1;  //ֻ����ȫ�ֱ��������ھֲ���ʹ�ÿ���������һ�����ú����ͻᱨ��
vector<int> &fun1()
{
    for(int i = 0; i < maxn; i++) v1.push_back(i);
    return v1;
}

vector<int> f1()
{
    vector<int> v;
    for(int i = 0; i < maxn; i++) v.push_back(i);
    return v;
}

vector<int> f2(vector<int> v)
{
    for(int i = 0; i < maxn; i++) v.push_back(i);
    return v;
}

void f3(vector<int> &v)
{
    for(int i = 0; i < maxn; i++) v.push_back(i);
    return;
}

void f4(int arr[])
{
    for(int i = 0; i < maxn; i++) arr[i] = i;
    return;
}

vector<int> v2;  //ָ�뺯��Ҳ��ͬ���ĵ�����Ҫ�ѵ�ַд���������ھֲ�����ж�̬�仯
vector<int> *fun2()
{
    for(int i = 0; i < maxn; i++) v2.push_back(i);
    return &v2;
}


vector<pair<int, int> > F1()
{
    clock_t tim = clock();
    vector<pair<int, int> > v;
    for(int i = 0; i < maxn; i++) v.push_back(make_pair(i, i));
    cout << "��ͨ = " << clock() - tim << endl;
    return v;
}

void F3(vector<pair<int, int> > &v)
{
    clock_t tim = clock();
    for(int i = 0; i < maxn; i++) v.push_back(make_pair(i, i));
    cout << "�������� = " << clock() - tim << endl;
    return;
}

int arr[maxn];
int main()
{
    clock_t tim = clock();
    vector<int> *a = fun2();
    cout << "ָ�뺯�� = " << clock() - tim << ' ' << (*a).size() << endl;

    tim = clock();
    vector<int> b = fun1();
    cout << "���ú��� = " << clock() - tim << ' ' << b.size() << endl;

    tim = clock();
    vector<int> c = f1();
    cout << "��ͨ�������� = " << clock() - tim << ' ' << c.size() << endl;

    tim = clock();
    vector<int> d;
    d = f2(d);
    cout << "������ͨ�������� = " << clock() - tim << ' ' << d.size() << endl;

    tim = clock();
    vector<int> e;
    f3(e);
    cout << "�������÷������� = " << clock() - tim << ' ' << e.size() << endl;

    tim = clock();
    f4(arr);
    cout << "�������鷵������ = " << clock() - tim << ' ' << arr[55] << endl;

    //��ͨ�������� and �������÷������� ����Ǻܴ�ʹ�ø��ӵ�����ͻ��ǣ�����
    tim = clock();
    vector<pair<int, int> > h = F1();
    cout << "��ͨ�������� = " << clock() - tim << ' ' << h.size() << endl;

    tim = clock();
    vector<pair<int, int> > j;
    F3(j);
    cout << "�������÷������� = " << clock() - tim << ' ' << j.size() << endl;
	return 0;
}
