#include <iostream>
using namespace std;
int main()
{	int digui(int n,int m);
	int n,m=1;
	while(cin>>n&&n!=0)
	cout<<digui(n,m)<<endl;
	return 0;
}

int digui(int n,int m)
{
	if(n==1)
	return m;
	if(n==2||n==3||n==4)
	{m+=1;
	return digui(--n,m);}
	else
	{m+=n-3;
	return digui(--n,m);}
}