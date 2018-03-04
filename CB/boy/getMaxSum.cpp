#include <iostream>
#include <string.h>
#include <algorithm>
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

template<class T>
int length(T& arr)
{
    //cout << sizeof(arr[0]) << endl;
    //cout << sizeof(arr) << endl;
    return sizeof(arr) / sizeof(arr[0]);
}

int getMaxSum(int arr[], int len)
{
    int dp[10005];
    for(int i = 0; i < len; i++) {
        dp[i] = arr[i];
        for(int j = i - 2; j >= 0; j--) {
            if(dp[j] + arr[i] > dp[i]) dp[i] = dp[j] + arr[i];
        }
    }
    return *max_element(dp, dp + len);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, -6, 7, 8};
    int len = length(arr);
    cout << getMaxSum(arr, len) << endl;
    return 0;
}
