#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.1415926 
using namespace std;
int main()
{
	double R,HR,HZ,m,n,i;
	double V,V1,V2;
	while(cin>>R>>HR>>HZ)
	{
		V1=pi*R*R*R*4/3;
 		V2=2*pi*HR*HR*HZ;   
 		m=sqrt(R*R-HR*HR);
 		
		if(HR>=R&&HZ>=R)         
			cout<<setprecision(6)<<fixed<<V1/V2<<endl;
			
		else if(HR*HR+HZ*HZ<=R*R)  
	        cout<<setprecision(6)<<fixed<<V2/V1<<endl;
	        
		else if(HZ<=R&&HR>=R)     
		{  
			V=2*pi*R*R*HZ-2*pi*HZ*HZ*HZ/3;
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;	
		} 
					
		else if(HZ>=R&&HR<=R)   
		{
			V=(R*R*R-m*m*m)*pi*4/3;
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;
		}
		
		else if (HR<=R&&HZ<=R)  
		{
			V=2*pi*HR*HR*m+2*pi*(R*R*(HZ-m)+(m*m*m-HZ*HZ*HZ)/3);
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;
		}
	}
	return 0;
}