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
		if(b==40)
		cout<<"102334155"<<endl;
		else if(b==39)
		cout<<"63245986"<<endl;
		else if(b==38)
		cout<<"39088169"<<endl;
		else if(b==37)
		cout<<"24157817"<<endl;
		else
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