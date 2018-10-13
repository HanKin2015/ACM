#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int eular(int n)
{
    int ret=1,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0) n/=i,ret*=i;
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

/*线性筛O(n)时间复杂度内筛出maxn内欧拉函数值*/
int m[maxn],phi[maxn],p[maxn],pt;//m[i]是i的最小素因数，p是素数，pt是素数个数

int make()
{
    phi[1]=1;
    int N=maxn;
    int k;
    for(int i=2;i<N;i++)
    {
        if(!m[i])//i是素数
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])//为了保证以后的数不被再筛，要break
            {
                phi[k]=phi[i]*p[j];
/*这里的phi[k]与phi[i]后面的∏(p[i]-1)/p[i]都一样（m[i]==p[j]）只差一个p[j]，就可以保证∏(p[i]-1)/p[i]前面也一样了*/
                break;
            }
            else
                phi[k]=phi[i]*(p[j]-1);//积性函数性质，f(i*k)=f(i)*f(k)
        }
    }
}

int main()
{
    int n;
    while(cin >> n) {
        //小于n的正整数中与n互质的数的数目
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(gcd(i, n) == 1) cnt++;
        }
        cout << cnt << endl;

        //根据通式计算
        int ans = n;
        for(int i = 2; i <= n; i++) {
            if(n % i == 0) {
                ans = (ans / i) * (i - 1);
            }
            while(n % i == 0) n /= i;
        }
        cout << ans << endl;
    }
    return 0;
}
