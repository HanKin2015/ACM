#include <iostream>
using namespace std;
int main()
{	int digui(int n);
	int n;
	while(cin>>n)
	if(!digui(n%8))
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	return 0;
}

int digui(int n)
{
	if(n==0)
	return 1;
	else if(n==1)
	return 2;
	else
	return (digui(n-1)+digui(n-2))%3;
 
}