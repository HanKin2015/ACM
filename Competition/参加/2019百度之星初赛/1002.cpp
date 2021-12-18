#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL mod = 1e9 + 7;

LL compute_time(LL n, LL a, LL b)
{
	LL ret;
	if (1 == (n % 2)) {
		LL tmp = n * n % mod;
		LL ans1 = tmp * n % mod;
		LL ans2 = tmp * (n - 1) % mod;
		ret = (ans1 * b + ans2 * a) % mod;
		return ret;
	}
	else {
		LL tmp = ((n / 2) * (n / 2) * 18) % mod;
		tmp = tmp * a % mod;
		tmp += 7 * compute_time(n / 2, a, b) % mod;
		ret = tmp % mod;

		LL tmp2 = n * n % mod;
		LL ans1 = tmp2 * n % mod;
		LL ans2 = tmp2 * (n - 1) % mod;
		LL ret1 = (ans1 * b + ans2 * a) % mod;
		if (ret < ret1) return ret;
		else return ret1;
	}
}

int main()
{

	LL t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		LL ans = compute_time(n, a, b);
		ans %= mod;
		cout << ans << endl;
	}
	return 0;
}