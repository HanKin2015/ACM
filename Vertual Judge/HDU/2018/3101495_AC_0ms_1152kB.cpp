#include <iostream>
using namespace std;
int main()
{	int digui(int n);
	int n;
	while(cin>>n&&n!=0)
	cout<<digui(n)<<endl;
	return 0;
}

int digui(int n)
{
	if(n==1)
	return 1;
	else if(n==2)
	return 2;
	else if(n==3)
	return 3;
	else
	return digui(n-1)+digui(n-3);
 
}