#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> nodes, temp;
    nodes.insert(1);
    nodes.insert(2);
    nodes.insert(3);
    temp.insert(2);
    temp.insert(3);
    temp.insert(4);
    vector<int> v;
    set_intersection(temp.begin(), temp.end(), nodes.begin(), nodes.end(), inserter(v, v.begin()));
    for(int i : v) cout << i << endl;

    int m, n;
    cin >> m;
    while(m--) {
        cin >> n;
        if(n % 3 == 0) cout << "don't be discouraged" << endl;
        else cout << "lucky" << endl;
    }
}
