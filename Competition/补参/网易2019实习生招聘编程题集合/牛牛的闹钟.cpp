#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10005
using namespace std;

int main()
{
    int N, H[maxn], M[maxn], temp[maxn], tmp, X, A, B;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> H[i] >> M[i];
        temp[i] = H[i] * 60 + M[i];
    }
    cin >> X;
    cin >> A >> B; tmp = A * 60 + B;
    sort(temp, temp + N);
    for(int i = N - 1; i>= 0;i--) {
        if(temp[i] <= tmp - X) {
            cout << temp[i] / 60 << ' ';
            cout << temp[i] % 60 << endl;
            break;
        }
    }
	return 0;
}
