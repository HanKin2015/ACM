#include <bits/stdc++.h>
#define LL long long
using namespace std;

//typedef long long LL;
const int mod = 1e9 + 7;

int compute_time2(LL n, LL a, LL b);

int compute_time1(LL n, LL a, LL b)
{
	LL tmp = (n * n) % mod;
	tmp = ((tmp * n) % mod * a + (tmp * (n - 1)) * b) % mod;
	int ans = tmp;
	//if (ans <= compute_time2(n, a, b)) printf("jishu%lld  ", n);
	//else printf("oushu%lld  ", n);
	//if (ans > compute_time2(n, a, b)) printf("oushu%lld  ", n);
	return min(ans, compute_time2(n, a, b));
}

int compute_time2(LL n, LL a, LL b)
{
	if (0 != n % 2) return INT_MAX;
	LL tmp = ((n / 2) * (n / 2) * 18 * b) % mod;
	tmp += 7 * compute_time1(n / 2, a, b) * a;
	tmp %= mod;
	return tmp;
}

int compute_time(LL n, LL a, LL b)
{
	printf("shuxinsanguan");
	cout << n << endl;
	LL ret;
	if (n % 2 == 1) {
		LL tmp = n * n % mod;
		LL ans1 = tmp * n % mod;
		LL ans2 = tmp * (n - 1) % mod;
		printf("n=%lld  ans1=%lld  ans2=%lld\n", n, ans1, ans2);
		cout << "dsa"<< n << endl;
		ret = (ans1 * b % mod + ans2 * a % mod) % mod;
		cout << ret <<'t' <<  endl;
	}
	else {
		LL tmp = ((n / 2) * (n / 2) * 18) % mod;
		tmp = tmp * a % mod;
		tmp += 7 * compute_time(n / 2, a, b) * b % mod;
		ret = tmp % mod;

		LL tmp2 = n * n % mod;
		LL ans1 = tmp2 * n % mod;
		LL ans2 = tmp2 * (n - 1) % mod;
		LL ret1 = (ans1 * b % mod + ans2 * a % mod) % mod;
		ret = min(ret, ret1);
	}
	return ret % mod;
}

int main()
{

	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		LL arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
		for (int i = 0; i < 11; i++) {
			cout << compute_time1(arr[i], a, b) << ' ';
			cout << arr[i] << ' ' << compute_time(arr[i], a, b) << endl;
		}
		//cout << compute_time(256, 5, 5) << ' ' << compute_time1(256, 5, 5) << endl;
		//cout << compute_time(n, a, b) << endl;
	}
	return 0;
}