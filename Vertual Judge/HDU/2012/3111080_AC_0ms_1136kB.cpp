#include <iostream>
using namespace std;
int main()
{
	bool sushu(int m);
	int a,b,i,s=1;
	while(cin>>a>>b&&!(a==0&&b==0))
	{for(i=a;i<=b;i++)
	{
		if(!sushu(i*i+i+41))
		s=0;
	}
	if(s)
	cout<<"OK"<<endl;
	else
	cout<<"Sorry"<<endl;
	s=1;}
	return 0;
}

bool sushu(int m)
{
	int i,n=1;
	for(i=2;i<m/2;i++)
	if(m%i==0)
	n=0;
	if(n)
	return true;
	else
	return false;
	
}