#include <iostream>
#include <algorithm>
#define LL __int64
using namespace std;
struct TrA{
	LL c[13][13];
};

int main()
{
	//freopen("data.txt","r",stdin);
	TrA ff_pow(TrA a,int n,int k);
	TrA fuzhi(TrA a,int n);
	int n,k,i;
	long long s=0;
	TrA b;
	LL e[11];
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<n+1;i++)
		cin>>e[i];
		e[0]=23;
		e[n+1]=3;
		b=fuzhi(b,n);
		b=ff_pow(b,n+2,k);
		for(i=0;i<n+2;i++)
		s+=e[i]*b.c[n][i]%10000007;
		cout<<s%10000007<<endl;
		s=0;
	}
	return 0;
}

TrA fuzhi(TrA a,int n)
{
	int i,j;
	for(i=0;i<n+2;i++)
	for(j=0;j<n+2;j++)
		a.c[i][j]=0;
	for(i=0;i<n+1;i++)
	{
		a.c[i][0]=10;
		a.c[i][n+1]=1;
	}
	a.c[n+1][n+1]=1;
	for(i=1;i<n+1;i++)
	for(j=1;j<n+1;j++)
	{
		if(i>=j)
		a.c[i][j]=1;
	}
	
	return a;
} 

TrA ff_pow(TrA a,int n,int k)
{
	TrA b,d;
	int j,l,x;
	k-=1;
    for(j=0;j<n;j++)
			for(l=0;l<n;l++)
		 		b.c[j][l]=a.c[j][l];
    while(k)
    {
    	for(j=0;j<n;j++)
		for(l=0;l<n;l++)
		d.c[j][l]=0;
        if(k&1)
		{
			for(j=0;j<n;j++)
			for(x=0;x<n;x++)
			for(l=0;l<n;l++)
				d.c[j][x]+=b.c[j][l]*a.c[l][x];
			
			for(j=0;j<n;j++)
			for(l=0;l<n;l++)
		 		b.c[j][l]=d.c[j][l]%10000007;
		 
		}
		
		for(j=0;j<n;j++)
		for(l=0;l<n;l++)
		d.c[j][l]=0;
		
	 	for(j=0;j<n;j++)
		for(x=0;x<n;x++)
		for(l=0;l<n;l++)
			d.c[j][x]+=a.c[j][l]*a.c[l][x];
			
		for(j=0;j<n;j++)
		for(l=0;l<n;l++)
		 	a.c[j][l]=d.c[j][l]%10000007;
 	
        k>>=1;
    }
    return b;
}