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

int next[MAX_N];

void GetNext(char c[])
{
    int Len=strlen(c);
    next[0]=-1;
    int k=-1,i=0;
    while(i<Len-1)
    {
        if(k==-1 ||c[i]==c[k]){
            k++,i++;
            next[i]=k;
        }
        else
            k=next[k];
    }
    return ;
}

void ValGetNext(char c[])
{
    int Len=strlen(c);
    next[0]=-1;
    int k=-1,i=0;
    while(i<Len-1)
    {
        if(k==-1 ||c[i]==c[k]){
            k++,i++;
            if(c[i]!=c[k])
                next[i]=k;
            else
                next[i]=next[k];
        }
        else
            k=next[k];
    }
    return ;
}

int kmp(char c1[],char c2[])
{
    int len1=strlen(c1),len2=strlen(c2);
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||c1[i]==c2[j])
            i++,j++;
        else
            j=next[j];
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
        int m,n;
        cin>>m>>n;
        char c1[MAX_N],c2[MAX_N];
        for(int i=0;i<m;i++)
            cin>>c1[i];
        for(int i=0;i<n;i++)
            cin>>c2[i];
        GetNext(c2);
        int ans=kmp(c1,c2);
        cout<<ans<<endl;
    }
    return 0;
}
