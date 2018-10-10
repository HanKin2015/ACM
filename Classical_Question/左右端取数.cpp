/*
有n堆石子,小何和小健每次只能从左右两端取, 小何先取,问最多能取多少???
*/
#include <iostream>
using namespace std;

int ans = -1;

void dfs(int l, int r, int arr[], int sum1, int sum2, int cnt)
{
    if(l > r) {
        if(sum1 >= sum2) {
            if(sum1 > ans) ans = sum1;
        }
        return;
    }
    if(cnt & 1) {
        dfs(l + 1, r, arr, sum1 + arr[l], sum2, cnt + 1);
        dfs(l, r - 1, arr, sum1 + arr[r], sum2, cnt + 1);
    }
    else {
        dfs(l + 1, r, arr, sum1, sum2 + arr[l], cnt + 1);
        dfs(l, r - 1, arr, sum1, sum2 + arr[r], cnt + 1);
    }
    return;
}

int main()
{
    int arr[] = {1, 5, 233, 7};
    dfs(0, 3, arr, 0, 0, 1);
    if(ans == -1) cout << "False" << endl;
    else cout << ans << endl;
    return 0;
}
