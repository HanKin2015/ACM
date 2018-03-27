#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int N, D, mat[105][105];
    cin >> N >> D;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = INT_MIN + 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int sum = 0;
            if(j + D - 1 < N) { //行或者右下
                for(int k = j; k < j + D; k++) {
                    sum += mat[i][k];
                }
                if(sum > ans) ans = sum;
                if(i + D - 1 < N) {
                    sum = 0;
                    for(int k = j; k < j + D; k++) {
                        sum += mat[i + k - j][k];
                    }
                    if(sum > ans) ans = sum;
                }
            }
            sum = 0;
            if(i + D - 1 < N) { //竖或者左下
                for(int k = i; k < i + D; k++) {
                    sum += mat[k][j];
                }
                if(sum > ans) ans = sum;
                if(j - D + 1 >= 0) {
                    sum = 0;
                    for(int k = j; k > j - D; k--) {
                        sum += mat[i + j - k][k];
                    }
                    if(sum > ans) ans = sum;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

