#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define MAX_N 110005
#define eps 1e-7
using namespace std;

const int maxn=1000010;
char str[maxn];
char tmp[maxn<<1];
int Len[maxn<<1];

int INIT(char *st)
{
    int i,len=strlen(st);
    tmp[0]='@';
    for(i=1;i<=2*len;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=st[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';
    tmp[2*len+3]=0;
    return 2*len+1;
}

int MANACHER(char *st,int len)
{
     int mx=0,ans=0,po=0;
     for(int i=1;i<=len;i++)
     {
         if(mx>i)
         Len[i]=min(mx-i,Len[2*po-i]);
         else
         Len[i]=1;
         while(st[i-Len[i]]==st[i+Len[i]])
         Len[i]++;
         if(Len[i]+i>mx)
         {
             mx=Len[i]+i;
             po=i;
         }
         ans=max(ans,Len[i]);
     }
     return ans-1;
  }

int main()
{
    //freopen("data.txt","r",stdin);
    ios::sync_with_stdio(false);
    char c[MAX_N];
    while(cin>>c){
    int leng=INIT(c);
//    for(int i=0;i<=leng;i++)
//        cout<<tmp[i];
//    cout<<endl;
    int ans=MANACHER(tmp,leng);
//    for(int i=0;i<=leng;i++)
//        cout<<Len[i];
//    cout<<endl;
    cout<<ans<<endl;
    }
    return 0;
}
