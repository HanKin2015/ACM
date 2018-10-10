#include <bits/stdc++.h>
using namespace std;

void min_between(int a[], int l, int r)
{
    if(l > r) return;
    int tag = l;
    for(int i = l; i <= r; i++) {
        if(a[i] < a[tag]) tag = i;
    }
    cout << a[tag] << ' ';   //先序遍历，先根部
    min_between(a, l, tag - 1); //左子树
    min_between(a, tag + 1, r); //右子树
    return;
}

int main()
{
    int N, a[105];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    min_between(a, 0, N - 1);
    return 0;
}
