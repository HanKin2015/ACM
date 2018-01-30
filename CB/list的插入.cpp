#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l1 = {1, 2, 3, 4};
    list<int> l2 = {5, 6, 7, 8};
    list<int> l3;
    l3.insert(l3.end(), l1.begin(), l1.end());
    l3.insert(l3.end(), l2.begin(), l2.end());
    cout << l3.size() << endl;
    if(l3.contains(5)) cout << "true" << endl;
    return 0;
}
