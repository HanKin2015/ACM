#include <iostream>
using namespace std;
int main()
{
	int n,i,s=1;
	while(cin>>n)
	{
		for(i=1;i<n;i++)
		{
			s=(s+1)*2;
		}
		cout<<s<<endl;
		s=1;
	}
	return 0;
}