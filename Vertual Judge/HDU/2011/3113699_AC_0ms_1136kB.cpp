#include <iostream>
using namespace std;
int main()
{
	double n,i,m,j,a=1,s=0;
	 cin>>n;
	 for(i=0;i<n;i++)
	 {
 		cin>>m;
 		for(j=1;j<=m;j++)
 		{
		 	s+=a*(1.0/j);
		 	a=-a;
		 }
		 printf("%.2f\n",s);
		 s=0;
		 a=1;
 	}
	return 0;
}