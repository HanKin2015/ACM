#include <iostream>
using namespace std;

bool Judge(int A[105][105], int i, int j) {
    int sum = A[i][j] + A[i][j + 1] + A[i][j + 2];
    if(A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2] != sum) return false;
    if(A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2] != sum) return false;
    if(A[i][j] + A[i + 1][j] + A[i + 2][j] != sum) return false;
    if(A[i][j + 1] + A[i + 1][j + 1] + A[i + 2][j + 1] != sum) return false;
    if(A[i][j + 2] + A[i + 1][j + 2] + A[i + 2][j + 2] != sum) return false;
    if(A[i][j] + A[i + 1][j + 1] + A[i + 2][j + 2] != sum) return false;
    if(A[i][j + 2] + A[i + 1][j + 1] + A[i + 2][j] != sum) return false;
    return true;
}

int main()
{
    int N, M, A[105][105];
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < N - 2; i++) {
        for(int j = 0; j < M - 2; j++) {
            if(Judge(A, i, j)) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
