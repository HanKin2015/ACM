#include <bits/stdc++.h>
#define LL long long
using namespace std;

void count_1_n(int n, int cnt[])
{
    for(int i = 1; i <= n; i++) {
        int temp = i, high;
        while(temp) {
            high = temp % 10;
            temp /= 10;
        }
        cnt[high] += n / i;
    }
    return;
}

void count_1_x(LL n, LL cnt[])
{
    for(int p = 1; p <= 9; p++) {   //最高位数码1-9
        for(LL q = 1; p * q <= n; q *= 10) {      //长度1-10
            LL d = p * q, maxn = min(p * q + q - 1, n);
            LL slip;
            for(LL i = d; i <= maxn; i += slip) {
                //cnt[p] += n / i;
                LL k = n / i;
                slip = (n % i) / k + 1;
                if(i + slip > maxn + 1) slip = maxn - i + 1;
                cnt[p] += k * slip;
            }
        }
    }
    return;
}

void count_1_y(int n, int cnt[])
{
    for(int q = 1; q <= 10; q++) {      //长度1-10
        for(int p = 1; p <= 9; p++) {   //最高位数码1-9
            //pow函数有精度问题，尽量少用
            for(LL d = round((p * pow(10, q - 1))); d < round((p + 1)*pow(10, q - 1)) && d <= n; d++) {
                cnt[p] += n / d;
            }
        }
    }
    return;
}

LL S(LL n, LL m)
{
    if(n == 0 || m == 0) return 0;
    LL res = 0, t = 0;
    m = min(n, m);
    for(t = 1; t <= m && t * t <= n; t++)
        res += n / t;
    for(LL i = n / t; i >= n / m; i--)
        res += (min(m, n / i) - n / (i + 1)) * i;
    return res;
}

void count_1_z(int n, int cnt[])
{
    for(int q = 1; q <= 10; q++) {      //长度1-10
        for(int p = 1; p <= 9; p++) {   //最高位数码1-9
            LL l = round((p * pow(10, q - 1))), r = round((p + 1)*pow(10, q - 1));
            cnt[p] += S(n, r) - S(n, l - 1);
        }
    }
    return;
}

int main()
{
    /*int cnt = 0;
    for(int i = 0; i < pow(10, 3) - 0.5; i++) {
        cout << "i = " << i << endl;
        cnt++;
    }
    cout << pow(10, 3) << endl;
    cout << cnt << endl;
    cout << round(123.54) << endl;*/
    int l, r;
    while(cin >> l >> r) {
        LL cnt_l[10] = { 0 }, cnt_r[10] = { 0 };
//        count_1_n(l - 1, cnt_l);
//        count_1_n(r, cnt_r);
//        for(int i = 1; i < 10; i++) cout << cnt_r[i] - cnt_l[i] << endl;
//
//        cout << endl;
//        memset(cnt_l, 0, sizeof(cnt_l));
//        memset(cnt_r, 0, sizeof(cnt_r));
        count_1_x(l - 1, cnt_l);
        count_1_x(r, cnt_r);
        for(int i = 1; i < 10; i++) cout << cnt_r[i] - cnt_l[i] << endl;

//        cout << endl;
//        memset(cnt_l, 0, sizeof(cnt_l));
//        memset(cnt_r, 0, sizeof(cnt_r));
//        count_1_y(l - 1, cnt_l);
//        count_1_y(r, cnt_r);
//        for(int i = 1; i < 10; i++) cout << cnt_r[i] - cnt_l[i] << endl;
    }
    return 0;
}

