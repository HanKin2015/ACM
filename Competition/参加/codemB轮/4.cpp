#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    node(int x) {
        this->x = x;
    }
    node(){}
};

int main()
{
    node t(5);
    cout << t.x << endl;
    node n[5];
    for(int i = 0; i < 5; i++) {
        n[i] = node(i);
        cout << n[i].x << endl;
    }
    return 0;
}
