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
int c1[MAX_N],c2[MAX_N];
int m,n;

void GetNext(int c[])
{
    int Len=n;
    nxt[0]=-1;
    int k=-1,i=0;
    while(i<Len-1)
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

int kmp(int a1[],int a2[])
{
    int len1=m,len2=n;
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||a1[i]==a2[j])
            i++,j++;
        else
            j=nxt[j];
    }
    if(j==len2)
        return i-j+1;
    return -1;
}

int main()
{
    //freopen("data.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int i=0;i<m;i++)
            scanf("%d",c1+i);
        for(int i=0;i<n;i++)
            scanf("%d",&c2[i]);
        GetNext(c2);
        int ans=kmp(c1,c2);
        cout<<ans<<endl;
    }
    return 0;
}
