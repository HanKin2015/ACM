#include <bits/stdc++.h>
using namespace std;

void min_between(int a[], int l, int r)
{
    if(l > r) return;
    int tag = l;
    for(int i = l; i <= r; i++) {
        if(a[i] < a[tag]) tag = i;
    }
    cout << a[tag] << ' ';   //����������ȸ���
    min_between(a, l, tag - 1); //������
    min_between(a, tag + 1, r); //������
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
