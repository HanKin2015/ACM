#include <bits/stdc++.h>
using namespace std;

bool cmp(double a, double b) {
    return a > b;
}

int main()
{
    double arr[5] = {0.234, 0.2123, 0.345, 0.123451, 0.51231};
    sort(arr, arr + 5);
    for(int i = 0; i < 5; i++) cout << arr[i] << endl;
    sort(arr, arr + 5, cmp);
    for(int i = 0; i < 5; i++) cout << arr[i] << endl;
}
