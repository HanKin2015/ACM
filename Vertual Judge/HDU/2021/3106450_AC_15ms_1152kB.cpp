#include <iostream>
using namespace std;
int main()
{
	int n,m,i,k=0;
	while(cin>>n&&n!=0)
	{for(i=0;i<n;i++)
	{
		cin>>m;
		while(m>0)
		{
			if(m>=100)
			{
				k++;
				m-=100;
			}
			else if(m>=50)
			{
				k++;
				m-=50;
			}
			else if(m>=10)
			{
				k++;
				m-=10;
			}
			else if(m>=5)
			{
				k++;
				m-=5;
			}
			else if(m>=2)
			{
				k++;
				m-=2;
			}
			else if(m>=1)
			{
				k++;
				m-=1;
			}
		}
	}
	cout<<k<<endl;
	k=0;}
	return 0;
}