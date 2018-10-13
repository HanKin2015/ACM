/*
��n��ʯ��,С�κ�С��ÿ��ֻ�ܴ���������ȡ, С����ȡ,�������ȡ����???

���Զ���dp���Ⱑ��f[i][j]=max(num[i] + sum[i+1][j] - f[i+1][j] , num[j] +  sum[i][j-1] - f[i][j-1])
f[i][j]��ʾ��i��jȡ������
sum[i][j]��ʾ��i��j�ĺ�
ÿ��ֻ���ж�����ߴ����ұߴ�ͺ���
*/
#include <iostream>
using namespace std;

// �����뵽���ѵ�ʱ���Ӧ�����뵽dp��̰�ġ�
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

// ��ȷ��������̬�滮
const int maxn = 105;
void solve(int num[], int len)
{
    int f[maxn][maxn] = {0}, sum[maxn][maxn];
    for (int i = 0; i < len; i++) {
        sum[i][i] = num[i];
        f[i][i] = num[i];
        for (int j = i + 1; j < len; j++) {
            sum[i][j] = num[j] + sum[i][j - 1];
            //cout << sum[i][j] << endl;
        }
    }
    for (int i = len - 2; i >= 0; i--) {
        for (int j = 1; j < len; j++) {
            f[i][j] = max(num[i] + sum[i+1][j] - f[i+1][j] , num[j] +  sum[i][j-1] - f[i][j-1]);
        }
    }
    cout << f[0][len - 1] << endl;
    return;
}

int main()
{
    int arr[] = {140, 649, 340, 982, 105, 86, 56, 610, 340, 879};
    dfs(0, 3, arr, 0, 0, 1);
    if(ans == -1) cout << "False" << endl;
    else cout << ans << endl;
    solve(arr, 10);
    return 0;
}
