#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Judge(char A[1005][1005], int i, int j, int k) {
    for(int a = i; a < i + k; a++) {
        for(int b = j; b < j + k; b++) {
            if(A[a][b] == A[a][b + 1] || A[a][b] == A[a + 1][b]) return false;
        }
    }
    return true;
}

int main()
{
    //同或操作，KMP算法的改变
    int N, M;
    char A[1005][1005];
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            //scanf("%c", &A[i][j]);
            A[i][j] = getchar();
        }
        getchar();
    }
    int ans = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 1; i + k < N, j + k < M; k++) {
                if(Judge(A, i, j, k)) {
                    if(k + 1 > ans) ans = k + 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

