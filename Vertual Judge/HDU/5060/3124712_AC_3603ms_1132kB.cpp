#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.1415926 
using namespace std;
int main()
{
	double R,HR,HZ,m;
	double V,V1,V2;
	while(scanf("%lf%lf%lf",&R,&HR,&HZ)!=EOF)
	{
		V1=pi*R*R*R*4/3;  //球体积V1 
 		V2=2*pi*HR*HR*HZ;   //圆柱体积V2  
 		m=sqrt(R*R-HR*HR);
 		
		if(HR>=R&&HZ>=R)            //圆柱包围球 
			cout<<setprecision(6)<<fixed<<V1/V2<<endl;
			
		else if(HR*HR+HZ*HZ<=R*R)   //球包围圆柱 
	        cout<<setprecision(6)<<fixed<<V2/V1<<endl;
	        
		else if(HZ<=R&&HR>=R)          //矮圆柱
		{  
			V=2*pi*R*R*HZ-2*pi*HZ*HZ*HZ/3;
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;	
		} 
					
		else if(HZ>=R&&HR<=R)     // 高圆柱 
		{
			V=(R*R*R-m*m*m)*pi*4/3;
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;
		}
		
		else if (HR<=R&&HZ<=R)  //两者相当 
		{
			V=2*pi*HR*HR*m+2*pi*(R*R*(HZ-m)+(m*m*m-HZ*HZ*HZ)/3);
			cout<<setprecision(6)<<fixed<<V/(V1+V2-V)<<endl;
		}
	}
	return 0;
}