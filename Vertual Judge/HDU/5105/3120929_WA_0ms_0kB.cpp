#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
	float l,r,a,b,c,d,s,x,y,u,i,max;
	while(cin>>a>>b>>c>>d>>l>>r)
	{if(a==0)
	{
		max=abs(-((c*c)/(4*b))+d);
		s=abs(b*l*l+c*l+d);
		x=abs(b*r*r+c*r+d);
		if(max<s)
		max=s;
		if(max<x)
		max=x;
		printf("%.2f\n",max);
	}
	else if((4*b*b-12*a*(c+d))<0)
	{
		max=abs(a*l*l*l+b*l*l+c*l+d);
		s=abs(a*r*r*r+b*r*r+c*r+d);
		if(max<s)
		max=s;
		printf("%.2f\n",max);
	}
	else
	{
		u=(-2*b+sqrt(4*b*b-12*a*(c+d)))/6*a;
		i=(-2*b-sqrt(4*b*b-12*a*(c+d)))/6*a;
		max=abs(a*u*u*u+b*u*u+c*u+d);
		s=abs(a*l*l*l+b*l*l+c*l+d);
		x=abs(a*r*r*r+b*r*r+c*r+d);
		y=abs(a*i*i*i+b*i*i+c*i+d);
		if(max<s)
		max=s;
		if(max<x)
		max=x;
		if(max<y)
		max=y;
		printf("%.2f\n",max);
	}}
	return 0;
}