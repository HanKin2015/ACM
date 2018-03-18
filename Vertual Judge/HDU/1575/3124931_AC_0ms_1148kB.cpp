#include <iostream>
using namespace std;
struct TrA{
	int c[11][11];
};

int main()
{
	//freopen("data.txt","r",stdin);
	int ff_pow(TrA a,int n,int k);
	int T,n,k,i,j,l;
	TrA b;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>n>>k;
		
		for(j=0;j<n;j++)
		for(l=0;l<n;l++)
		cin>>b.c[j][l];
		
		ff_pow(b,n,k);
	}
	return 0;
}

int ff_pow(TrA a,int n,int k)
{
	TrA b,d;
	int j,l,x,s=0;
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
		 		b.c[j][l]=d.c[j][l]%9973;
		 
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
		 	a.c[j][l]=d.c[j][l]%9973;
		 	
        k>>=1;
    }
    for(j=0;j<n;j++)
		s+=b.c[j][j];
	cout<<s%9973<<endl;
    return 0;
}