#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int seed = 58;
    srand(seed);
    int num_max = 2147483647;
    mt19937 mt_time(seed);
	uniform_int_distribution<int> dist(1, num_max);  //[1, num_max]间的随机整数
    for(int i = 0; i < 10; i++) {
        int node = dist(mt_time); //[1, num_max]间的随机整数
        int number = node % 10;
        cout << number <<endl;
    }
    int n, cnt = 0;
    cin >> n;
    int num[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        if(num[i] <= num[0]) cnt++;
    }
    int ans = log2(cnt);
    cout << ans << endl;
    return 0;
}
