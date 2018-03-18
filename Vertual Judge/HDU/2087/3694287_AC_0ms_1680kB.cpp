#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define MAX_N 1000005
#define eps 1e-7
using namespace std;

int nxt[MAX_N];
char c1[MAX_N],c2[MAX_N];

void GetNext(char c[])
{
    int Len=strlen(c);
    nxt[0]=-1;
    int k=-1,i=0;
    while(i<Len)
    {
        if(k==-1||c[i]==c[k]){
            k++,i++;
            nxt[i]=k;
        }
        else
            k=nxt[k];
    }
    return ;
}

int kmp(char a1[],char a2[])
{
    int len1=strlen(a1),len2=strlen(a2);
    int i=0,j=0;
    int cnt=0;
    while(i<len1)
    {
        if(j==-1||a1[i]==a2[j])
            i++,j++;
        else
            j=nxt[j];
        if(j==len2){
            cnt++;
//            i=i-j+1;
//            j=0;
            j=0;
        }
    }
    return cnt;
}

int main()
{
    //freopen("data.txt","r",stdin);
    while(cin>>c1&&c1[0]!='#')
    {
        cin>>c2;
        GetNext(c2);
        int ans=kmp(c1,c2);
        cout<<ans<<endl;
    }
    return 0;
}
