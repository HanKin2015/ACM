#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        double W,H,x,xe,ye;
        double u,h;
        cin>>W>>H>>x>>xe>>ye>>u;
        double X=xe-W,Y=ye-H;
        double a=xe-x-ye*(X/Y),b=u*u*(1+(Y*Y)/(X*X))-1;
        h=a/(1/sqrt(b)-X/Y);
        if(h>H)
            cout<<"Impossible"<<endl;
        else
            cout<<setprecision(4)<<fixed<<h<<endl;
    }
    return 0;
}
