#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
    // string可以使用==判断，char数组则需使用strcmp
    char a[] = "test";
    char b[] = "test";
    char *p = "test";
    char *t = "test";
    char *q = "test ";
    a[4] = '\0';
    a[4] = '\0';
    if (a == b) cout << 1 << endl;
    if (p == t) cout << 2 << endl;   
    if (p == q) cout << 3 << endl;
    if (strcmp(a, b) == 0) cout << 4 << endl;
    cout << a << endl;
    cout << b << endl;
    cout << p << endl;
    cout << t << endl;
    cout << *p << endl;
    cout << *t << endl;
    return 0;
}