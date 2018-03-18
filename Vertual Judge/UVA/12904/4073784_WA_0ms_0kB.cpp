#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    const int maxn=10005;
    int T,N,arr[maxn],tmp[165],a,b,c,cnt=0;
    cin>>T;
    while(T--){
        cnt++;
        cin>>N;
        double ave=N/4.0,ret=200.0;
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<N;i++){
            cin>>arr[i];
            tmp[arr[i]]=i+1;
        }
        for(int i=0;i<=160;i++){
            for(int j=i+1;j<=160;j++){
                for(int k=j+1;k<=160;k++){
                    if(tmp[i]&&tmp[j]&&tmp[k]){
                        double ans=abs(tmp[i]-ave)+abs(tmp[j]-tmp[i]-ave)+abs(tmp[k]-tmp[j]-ave);
                        if(ans<ret){
                            ret=ans;
                            a=i,b=j,c=k;
                        }
                    }
                }
            }
        }
        cout<<"Case "<<cnt<<": "<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}
