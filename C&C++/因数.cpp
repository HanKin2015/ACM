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

/*����ɸO(n)ʱ�临�Ӷ���ɸ��maxn��ŷ������ֵ*/
int m[maxn],phi[maxn],p[maxn],pt;//m[i]��i����С��������p��������pt����������

int make()
{
    phi[1]=1;
    int N=maxn;
    int k;
    for(int i=2;i<N;i++)
    {
        if(!m[i])//i������
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])//Ϊ�˱�֤�Ժ����������ɸ��Ҫbreak
            {
                phi[k]=phi[i]*p[j];
/*�����phi[k]��phi[i]����ġ�(p[i]-1)/p[i]��һ����m[i]==p[j]��ֻ��һ��p[j]���Ϳ��Ա�֤��(p[i]-1)/p[i]ǰ��Ҳһ����*/
                break;
            }
            else
                phi[k]=phi[i]*(p[j]-1);//���Ժ������ʣ�f(i*k)=f(i)*f(k)
        }
    }
}

int main()
{
    int n;
    while(cin >> n) {
        //С��n������������n���ʵ�������Ŀ
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(gcd(i, n) == 1) cnt++;
        }
        cout << cnt << endl;

        //����ͨʽ����
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
