#include <bits/stdc++.h>
using namespace std;

//参数传递确实会花费时间
void fun1(vector<int> v1, vector<int> v2, vector<int> v3)
{
    //int cnt = 0;
    //for(int i = 0; i < 10000000; i++) cnt++;
    return;
}

//参数传递确实会花费时间
void fun2(vector<int> v1, vector<int> v2, vector<int> v3)
{
    for(int i = 0; i < v1.size(); i++) {
        v1.pop_back();
        v2.pop_back();
        v3.pop_back();
    }
    return;
}

//全局变量能节省时间
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

//参数传递地址
void fun4(vector<int>::iterator v1, vector<int>::iterator v2, vector<int>::iterator v3, int len)
{
    //是个不错的想法
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
    cout << "参数传递的时间fun1 = " << clock() - tim << endl; //45-48

    tim = clock();
    fun2(v, v, v);
    cout << "参数传递和计算的时间fun2 = " << clock() - tim << endl; //1665-1726

    tim = clock();
    fun3();
    cout << "计算的时间fun3 = " << clock() - tim << endl; //1605-1705
    return 0;
}
