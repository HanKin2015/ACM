#include <iostream>
using namespace std;
int main()
{
    int n,i,s;
    while(cin>>n&&n!=0)
    {
        int m[n];
        for(i=0;i<n;i++)
        cin>>m[i];
        s=m[0]*6;
        for(i=1;i<n;i++)
        {
            if(m[i]>m[i-1]) s+=(m[i]-m[i-1])*6;
            else s+=(m[i-1]-m[i])*4;
        }
        cout<<s+n*5<<endl;
    }
    return 0;
}