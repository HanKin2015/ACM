#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int N, P[105], arr[105];
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> P[i];
        arr[i] = i;
    }
    int cnt[105];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= N; i++) {
        int tmp = P[i];
        cnt[i]++;
        while(tmp != i) {
            cnt[i]++;
            tmp = P[tmp];
        }
//        cout << cnt[i] << endl;
    }
    int lcm = cnt[1];
    for(int i = 2; i <= N; i++) {
        lcm = lcm / gcd(lcm, cnt[i]) * cnt[i];
    }
    if(lcm == 1) lcm = 0;
    cout << lcm << endl;
    return 0;
}

