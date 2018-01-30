#include <iostream>
#include <list>
#include <set>
using namespace std;

struct node{
    int id;
    string str;
    list<int> L;
};

int main()
{
    node x;
    x.id = 2;
    x.str = "hejian";
    x.L.push_back(12);
    x.L.push_back(22);
    x.L.push_back(12);
    x.L.push_back(22);
    node y = x;
    cout << y.L.size() << endl;

    set<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    for(int i : s) cout << i << endl;
    cout << s[1] << endl;
    return 0;
}
