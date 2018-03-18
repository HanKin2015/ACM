#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char c[100];
	int n,i,j,k,m,l=1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>c;
		m=strlen(c);
		for(j=0,k=m-1;j<m,k>=0;j++,k--)
		if(c[j]!=c[k])
		l=0;
		if(!l)
		cout<<"no"<<endl;
		else
		cout<<"yes"<<endl;
		l=1;
	}
	return 0;
}