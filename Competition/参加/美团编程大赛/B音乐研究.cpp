#include<stdio.h>
long long a[10];
void p(long long n,bool mod)
{
    long long cnt=0,ans=0;
    for(long long i=1;i<10;i++)
    {
        for(long long base=1;base*i<=n;base*=10)
        {
            long long st=base*i,ed=st+base-1>n?n:st+base-1;
            for(long long j=st;j<=ed;j+=cnt)
            {
                ans=n/j,cnt=(n%j)/ans+1;
                if(j+cnt>ed+1) cnt=ed-j+1;
                if(mod) a[i]+=cnt*ans;
                else a[i]-=cnt*ans;
            }
        }
    }
}
int main()
{
    long long l,r;
    scanf("%lld%lld",&l,&r);
    p(l-1,0),p(r,1);
    for(int i=1;i<10;i++)
    printf("%lld\n",a[i]);

    return 0;
}
