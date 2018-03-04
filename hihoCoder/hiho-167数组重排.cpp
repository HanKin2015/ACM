#include <iostream>
using namespace std;

bool judge(int arr[], int N) {
    for(int i = 1; i <= N; i++) {
        if(arr[i] != i) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N, P[105], arr[105], brr[105];
    cin >> N;
    int start = 1;
    bool flag = true;
    for(int i = 1; i <= N; i++) {
        cin >> P[i];
        if(P[i] != i) flag = false;
        arr[i] = brr[i] = i;
    }
    if(flag) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    do {
        for(int i = 1; i <= N; i++) {
            brr[P[i]] = arr[i];
        }
        for(int i = 1; i <= N; i++) {
            arr[i] = brr[i];
        }
        cnt++;
    } while(!judge(arr, N));
    cout << cnt << endl;
    return 0;
}
