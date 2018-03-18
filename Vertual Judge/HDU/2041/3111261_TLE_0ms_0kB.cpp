#include <iostream>
using namespace std;
int main()
{
	int digui(int m);
	int a,b,i;
	cin>>a;
	for(i=0;i<a;i++)
	{
		cin>>b;
		cout<<digui(b)<<endl;
	}
	return 0;
}
int digui(int m)
 {
 	if(m==1)
 	return 0;
 	if(m==2)
 	return 1;
 	if(m==3)
 	return 2;
 	return digui(m-1)+digui(m-2);
 }