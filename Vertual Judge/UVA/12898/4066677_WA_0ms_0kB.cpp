#include <iostream>
using namespace std;

typedef long long ll;
const int maxn=65;
int T,cnt=0;
ll A,B,OR=0,AND=0;
int A_bit[maxn],B_bit[maxn];

int bit(ll x,int *arr){
    int leng=0;
    while(x){
        arr[leng++]=x&1;
        x>>=1;
    }
    return leng;
}

void cal()
{
    ll tmp=1;
    int leng1=bit(A,A_bit),leng2=bit(B,B_bit);
    if(leng1!=leng2){
        OR=(tmp<<leng2);
        return ;
    }
    else if(leng1==leng2){
        while(leng2>0&&A_bit[leng2-1]==B_bit[leng2-1])
            leng2--;
        OR=(tmp<<leng1);
        for(int i=leng2;i<leng1;i++)
            AND+=(1<<i);
    }
    return ;
}

int main()
{
    cin>>T;
    while(T--){
        cnt++;
        cin>>A>>B;
        AND=0;
        cal();
        cout<<"Case "<<cnt<<": "<<OR-1<<' '<<AND<<endl;
    }
    return 0;
}
