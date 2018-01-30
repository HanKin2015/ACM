#include <iostream>
using namespace std;

typedef long long LL;
LL n,M[4]={0,1,1,1},tmp[4]={1,0,0,1},t[4];
const int MOD=19999997;

void cal(LL a[],LL b[])
{
    t[0]=a[0]*b[0]+a[1]*b[2];
    t[1]=a[0]*b[1]+a[1]*b[3];
    t[2]=a[2]*b[0]+a[3]*b[2];
    t[3]=a[2]*b[1]+a[3]*b[3];
    return ;
}

int pow_quick(LL nn)
{
    while(nn){
        if(nn&1){
            cal(tmp,M);
            for(int i=0;i<4;i++)
                tmp[i]=t[i]%MOD;
        }
        cal(M,M);
        for(int i=0;i<4;i++)
            M[i]=t[i]%MOD;
        nn>>=1;
    }
    return 0;
}

int main()
{
    cin>>n;
    pow_quick(n);
//    for(int i=0;i<4;i++)
//        cout<<tmp[i]<<endl;
    cout<<tmp[3]%MOD;
    return 0;
}

