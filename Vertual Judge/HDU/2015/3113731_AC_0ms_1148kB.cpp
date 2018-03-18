#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int i,a,b,s=0,n=0,m=0;
    while(cin>>a>>b)
    {
        for(i=2;m<a;i+=2)
        {
            s+=i;
            m++;
            if(m%b==0)
            {
            n++;
            if(m==a)
            cout<<s/b;
            else
            cout<<s/b<<' ';
            s=0;}
            if(n==a/b&&m==a&&a>n*b)
            cout<<s/(a-n*b);
        }
        m=0;
        n=0;
        s=0;
        cout<<endl;
    }
    return 0;
    } 