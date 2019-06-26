#include <bits/stdc++.h>
using namespace std;

int main()
{
    int maxn = 1005;
    int **arr = new int*[maxn];
    for (int i = 0; i < maxn; i++) arr[i] = new int[maxn];   // зЂвт
    arr[5][5] = 23;
    memset(arr, 0, sizeof(arr));
    cout << arr[5][5] << endl;
    return 0;
}
