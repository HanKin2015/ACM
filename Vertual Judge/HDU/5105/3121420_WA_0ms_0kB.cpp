#include <iostream>
#include <cmath>
using namespace std;

double l,r,a,b,c,d,s,x,y,u,i,ans;

double f(double m)
{
	return abs(a*m*m*m+b*m*m+c*m+d);
}

bool judge(double m)
{
        return m<=r&&m>=l;
}

int main()
{
	while(cin>>a>>b>>c>>d>>l>>r)
	{
		if(a==0)
		{
			if(b==0||judge(!(-c/(2*b))))  
			ans=max(f(l),f(r));
			else
			{ans=max(f(l),f(r));
			ans=max(ans,f(b));}
			printf("%.2f\n",ans);
		}
		else if((4*b*b-12*a*c)<=0)       
		{
			ans=max(f(l),f(r));
			printf("%.2f\n",ans);
		}
		else
		{
			u=(-2*b+sqrt(4*b*b-12*a*c))/(6*a);
			i=(-2*b-sqrt(4*b*b-12*a*c))/(6*a);
			ans=max(f(l),f(r));
			if(judge(u))
			ans=max(ans,f(u));
			if(judge(i))
			ans=max(ans,f(i));
			printf("%.2f\n",ans);
		}
	}
	return 0;
}