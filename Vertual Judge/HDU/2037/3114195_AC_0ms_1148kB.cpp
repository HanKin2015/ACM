#include <iostream>
#include <algorithm>
using namespace std;

struct tanxin
{
	int a,b;
}t[120];

bool cmp(tanxin c,tanxin d)
{
	return (c.b-d.b)<0;
}

int main()
{
	int n,i,min,m=0;
	while(cin>>n&&n!=0)
	{for(i=0;i<n;i++)
	cin>>t[i].a>>t[i].b;
	sort(t,t+n,cmp);
	min=t[0].a;
 	for(i=0;i<n;i++)
 	{
	 	if(t[i].a>=min)
	 	{
	 		m++;
	 		min=t[i].b;
	 	}
	 }
	 cout<<m<<endl;
	 m=0;}
	return 0;
}