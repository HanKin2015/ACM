#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
	freopen("data.txt","r",stdin);
	double l,r,a,b,c,d,s,x,y,u,i,max;
	while(cin>>a>>b>>c>>d>>l>>r)
	{if(a==0)
	{
		if(b==0||-c/(2*b)<l||-c/(2*b)>r)
		{max=abs(c*l+d);
		s=abs(c*r+d);
		if(max<s)
		max=s;}
		else
		{max=abs(-((c*c)/(4*b))+d);
		s=abs(b*l*l+c*l+d);
		x=abs(b*r*r+c*r+d);
		if(max<s)
		max=s;
		if(max<x)
		max=x;}
		printf("%.2f\n",max);
	}
	else if((4*b*b-12*a*(c+d))<=0)
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
		if(i<l&&u>=l&&u<=r)
		{
			max=abs(a*u*u*u+b*u*u+c*u+d);
			s=abs(a*l*l*l+b*l*l+c*l+d);
			x=abs(a*r*r*r+b*r*r+c*r+d);
			if(max<s)
			max=s;
			if(max<x)
			max=x;
		}
		else if(i>r||u<l)
		{max=abs(a*l*l*l+b*l*l+c*l+d);
		x=abs(a*r*r*r+b*r*r+c*r+d);
		if(max<x)
		max=x;}
		else if(i>=l&&i<=r&&u>r)
		{max=abs(a*i*i*i+b*i*i+c*i+d);
		s=abs(a*l*l*l+b*l*l+c*l+d);
		x=abs(a*r*r*r+b*r*r+c*r+d);
		if(max<s)
		max=s;
		if(max<x)
		max=x;}
		else
		{max=abs(a*u*u*u+b*u*u+c*u+d);
		s=abs(a*l*l*l+b*l*l+c*l+d);
		x=abs(a*r*r*r+b*r*r+c*r+d);
		y=abs(a*i*i*i+b*i*i+c*i+d);
		if(max<s)
		max=s;
		if(max<x)
		max=x;
		if(max<y)
		max=y;}
		printf("%.2f\n",max);
	}}
	return 0;
}