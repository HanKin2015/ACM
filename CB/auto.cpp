#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    long a = 10;
    auto au_a = a;//自动类型推断，au_a为int类型
    cout << typeid(au_a).name() << endl;
    /*
    int     i
    float   f
    string  NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    long long x
    long    l
    */
    string str{"23333"};
    cout << str << endl;
    return 0;
}
