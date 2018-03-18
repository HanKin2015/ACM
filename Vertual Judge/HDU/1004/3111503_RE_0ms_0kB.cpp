#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string str[100];
	int i,n,j,a[100],max,k=0;
	while(cin>>n&&n!=0)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		cin>>str[i];
		for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(str[i]==str[j])
		a[i]++;
		max=a[0];
		for(i=1;i<n;i++)
		if(a[i]>max)
		{
			max=a[i];
			k=i;
		}
		cout<<str[k]<<endl;
		k=0;
	}
	return 0;
}