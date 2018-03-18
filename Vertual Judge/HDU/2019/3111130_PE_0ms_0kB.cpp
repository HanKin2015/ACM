#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)
        break;
        int i,a[101];
        a[0]=n;
        for(i=1;i<=m;i++)
        cin>>a[i];
        sort(a,a+m+1);
        for(i=0;i<=m;i++)
        cout<<' '<<a[i];
        cout<<' '<<endl;
    }
    return 0;
}
