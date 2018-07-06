#include <bits/stdc++.h>
#define LL long long
#define maxn 30000005
using namespace std;

vector<int> v1;  //只能是全局变量，放在局部不使用看不出来，一旦调用函数就会报错
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

vector<int> v2;  //指针函数也是同样的道理，需要把地址写死，不能在局部里会有动态变化
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
    cout << "普通 = " << clock() - tim << endl;
    return v;
}

void F3(vector<pair<int, int> > &v)
{
    clock_t tim = clock();
    for(int i = 0; i < maxn; i++) v.push_back(make_pair(i, i));
    cout << "参数引用 = " << clock() - tim << endl;
    return;
}

int arr[maxn];
int main()
{
    clock_t tim = clock();
    vector<int> *a = fun2();
    cout << "指针函数 = " << clock() - tim << ' ' << (*a).size() << endl;

    tim = clock();
    vector<int> b = fun1();
    cout << "引用函数 = " << clock() - tim << ' ' << b.size() << endl;

    tim = clock();
    vector<int> c = f1();
    cout << "普通返回类型 = " << clock() - tim << ' ' << c.size() << endl;

    tim = clock();
    vector<int> d;
    d = f2(d);
    cout << "参数普通返回类型 = " << clock() - tim << ' ' << d.size() << endl;

    tim = clock();
    vector<int> e;
    f3(e);
    cout << "参数引用返回类型 = " << clock() - tim << ' ' << e.size() << endl;

    tim = clock();
    f4(arr);
    cout << "参数数组返回类型 = " << clock() - tim << ' ' << arr[55] << endl;

    //普通返回类型 and 参数引用返回类型 差别不是很大，使用复杂点的类型会是？？？
    tim = clock();
    vector<pair<int, int> > h = F1();
    cout << "普通返回类型 = " << clock() - tim << ' ' << h.size() << endl;

    tim = clock();
    vector<pair<int, int> > j;
    F3(j);
    cout << "参数引用返回类型 = " << clock() - tim << ' ' << j.size() << endl;
	return 0;
}
