#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp_as_int(double i, double j)
{
    return (int(i)<int(j));
}

int main()
{
    double mydoubles[] = { 3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58 };
    vector<double> v;
    vector<double>::iterator it;

    v.assign(mydoubles, mydoubles + 8);

    cout << "use default comparison:" << endl;
    stable_sort(v.begin(), v.end());

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "use selfdefined comparison function comp_as_int():" << endl;
    v.assign(mydoubles, mydoubles + 8);
    //stable sort 是稳定排序。
    stable_sort(v.begin(), v.end(), comp_as_int);

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "use comparison function comp_as_int():" << endl;
    v.assign(mydoubles, mydoubles + 8);
    //sort是不稳定排序。
    sort(v.begin(), v.end(), comp_as_int);

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "if it is not sorted with stable_sort(), the sequence of all elements between 1 and 2 will be set randomly..." << endl;


    int n;
    cin >> n;
    return 0;
}
