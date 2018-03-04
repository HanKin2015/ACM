#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, arr[1005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int min_value = arr[1] - arr[0];
    for(int i = 2; i < n; i++) {
        int temp = arr[i] - arr[i - 1];
        if(temp < min_value) min_value = temp;
    }
    cout << min_value << endl;
    return 0;
}
