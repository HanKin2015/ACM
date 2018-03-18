#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int m,i,a[100];
	double s=0;
	while(cin>>m)
	{
		for(i=0;i<m;i++)
		cin>>a[i];
		sort(a,a+m);
		for(i=1;i<m-1;i++)
		s+=a[i];
		printf("%.2f\n",s/(m-2));
		s=0;
	}
	return 0;
}