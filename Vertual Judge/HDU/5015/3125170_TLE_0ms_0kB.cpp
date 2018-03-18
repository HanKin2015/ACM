#include <iostream>
using namespace std;

int haha(int b[],int n,int m)
{
	int i,k,j=1;
	int a[20];
	a[0]=23;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{a[j]=a[0]*10+3;
		a[0]=a[j];}
		j++;
		a[j]=a[j-1]%10000007+b[i]%10000007;
		if(j==n+1)
		{
		m--;
		i=-1;
		j=1;
		for(k=0;k<n;k++)
		b[k]=a[k+2];
		if(m==0)
		break;}
	}
	cout<<b[n-1]%10000007<<endl;
	return 0;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int m,n,i;
	int b[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		cin>>b[i];
		haha(b,n,m);
	}
	return 0;
}