/*
�ݹ�����
3��ƿ�ӻ�1ƿˮ+1����ƿ�ӣ�����ƿ�ӻ�1ƿˮ+0����ƿ�ӣ�1��ƿ�ӻ�0ƿˮ��

ͨ����ѧ����������õ����������ܿ�ƿ������2 ��
*/
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

int f(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return f(n-2)+1;
}

int main()
{
    int n;
    while(cin >> n) {
        if(n == 0) break;
        int ans = 0;
        while(n >= 3) {
            ans += n / 3;
            n = n / 3 + n % 3;
        }
        if(n == 2) ans++;
        cout << ans << endl;
    }
	return 0;
}
