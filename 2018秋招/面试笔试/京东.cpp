/*
贪心：对a,b,c其中一个排序,因为不合格物品三个条件都要满足,所以可以取一个最大值
*/
#include <bits/stdc++.h>
using namespace std;

struct ST {
    int a, b, c;
    ST(int _a, int _b, int _c):a(_a),b(_b),c(_c){}
    ST(){}
    void Assign(int _a, int _b, int _c) {
        a = _a; b = _b; c = _c;
    }
};

bool cmp(ST x, ST y) {
    return x.a > y.a;
}

const int maxn = 1e5;

int main()
{
    int aa[maxn];
    int n, a, b, c;
    ST *things = new ST[maxn];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        //things[i].Assign(a, b, c);

        //ST tmp(a,b,c);
        //things[i]= tmp;
    }/*
    sort(things, things + n, cmp);
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (things[i].a < things[0].a && things[i].b < things[0].b && things[i].c < things[0].c) cnt++;
    }
    cout << cnt << endl;*/
    return 0;
}
