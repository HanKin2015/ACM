#include <iostream>
using namespace std;
int main()
{
	char c;
	int m,i,k=1,n=0;
	cin>>m;
	c=getchar();
	for(i=0;i<m;i++)
	{while((c=getchar())!='\n')
	{
		if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='_')&&n==0)
		k=0;
		else if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')||c=='_'||(c>='0'&&c<='9')))
		k=0;
		n++;
	}
	if(k)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	k=1;
	n=0;
	}
	return 0;
}