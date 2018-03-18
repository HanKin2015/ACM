#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[100],b[100],c[100];
	int m,n,i,j,k=1,l=0;
	while(cin>>m>>n&&!(m==0&&n==0))
	{
		for(i=0;i<m;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		cin>>b[i];
		for(i=0;i<m;i++)
		{for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			k=0;
		}
			if(k)
			{c[l]=a[i];
			l++;}k=1;}
			if(l==0)
			cout<<"NULL"<<endl;
			else
			{sort(c,c+l);
			for(i=0;i<l;i++)
			cout<<c[i]<<' ';
			cout<<endl;
			l=0;}
	}
	return 0;
}