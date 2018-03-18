#include <iostream>
#define max_size 10000
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

struct Matrix{
	int a[10][max_size];
};

int haha(Matrix b,int n,int m)
{
	int i,j;
	b.a[0][1]=233;
	for(i=2;i<=m;i++)
	b.a[0][i]=b.a[0][i-1]*10+3;
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	{
		b.a[j][i]=b.a[j][i-1]+b.a[j-1][i];
	}
	cout<<b.a[n][m]%10000007<<endl;
	return 0;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int m,n,i;
	Matrix b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		cin>>b.a[i][0];
		haha(b,n,m);
	}
	return 0;
}