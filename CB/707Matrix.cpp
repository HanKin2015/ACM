#include <iostream>
using namespace std;

int ans;

void dfs(int arr[], int dex, bool flag[], int N) {
    if(dex == 3 && arr[1] + arr[2] >= N) return;
    if(dex == 4 && arr[1] + arr[3] >= N) return;
    if(dex == 5) {
        arr[5] = N - arr[1] - arr[3];
        arr[6] = N - arr[2] - arr[4];
        arr[7] = N - arr[1] - arr[2];
        arr[8] = N - arr[3] - arr[4];
        arr[9] = N - arr[7] - arr[8];
        for(int i = 1; i <= 9; i++) if(arr[i] < 1) return;
        for(int i = 5; i <= 9; i++) if(flag[arr[i]]) return;
        if((arr[5]+arr[6]+arr[9] == N)&&(arr[1]+arr[4]+arr[9] == N)&&(arr[5]+arr[4]+arr[7] == N)) {
           ans++;
        }
        return;
    }
    if(dex > 5) return;
    for(int i = 1; i <= N; i++) {
        if(!flag[i]) {
            flag[i] = true;
            arr[dex] = i;
            dfs(arr, dex+1, flag, N);
            flag[i] = false;
        }
    }
    return;
}

int main()
{
    int N;
//    for(N = 12; N <= 100; N++){
//        ans = 0;
//        int arr[10];
//        bool flag[105];
//        for(int i = 0; i < 105; i++) flag[i] = false;
//        dfs(arr, 1, flag, N);
//        cout << ans << ',';
//    }
    int num[105] = {0,0,0,8,0,0,24,0,0,32,0,0,56,0,0,80,0,0,104,0,0,136,0,0,176,0,0,208,0,0,256,0,0,304,0,0,352,0,0,408,0,0,472,0,0,528,0,0,600,0,0,672,0,0,744,0,0,824,0,0,912,0,0,992,0,0,1088,0,0,1184,0,0,1280,0,0,1384,0,0,1496,0,0,1600,0,0,1720,0,0,1840,0};
    while(cin >> N) {
        cout << num[N - 12] << endl;
    }
    return 0;
}
