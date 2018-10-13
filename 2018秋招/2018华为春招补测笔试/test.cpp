#include <bits/stdc++.h>
using namespace std;

void f(map<int, int> &m, int arr[])
{
    cout << m[2] <<endl;
    m[2] = 3;
    arr[2] = 3;
    return;
}

//point function
vector<int> *fun()
{
    vector<int> v;
    v.push_back(2);
    return &v;
}

int main()
{
    int a = 2, b = 3;
    swap(a, b);
    cout << a << ' ' << b << endl;
    vector<int> *v;
    v = fun();
    cout << v->size() << endl;
    map<int, int> m;
    int arr[] = {5, 5, 5, 5};
    m[2] = 5;
    cout << m[2] << endl;
    cout << arr[2] << endl;
    f(m, arr);
    cout << m[2] <<endl;
    cout << arr[2] << endl;

    set<pair<int, int> > han;
    for (int i = 0; i < 10; i++) { //Find G[W_] from the subgraph from Hi
        int node_u = i, node_v = i + 1;
        auto it1 = find(han.begin(), han.end(), make_pair(node_u, 1));
        if (it1 == han.end()) {
            han.insert(make_pair(node_u, 1));
        }
        auto it2 = find(han.begin(), han.end(), make_pair(node_v, 1));
        if (it2 == han.end()) {
            han.insert(make_pair(node_v, 1));
        }
        //if (hj[node_u] == 2 || hj[node_v] == 2) continue;
    }
    return 0;
}

