#include <stdio.h>
#include <string.h>

int nxt[10005];
char c1[1000005],c2[10005];

void GetNext(char c[])
{
    int Len=strlen(c);
    nxt[0]=-1;
    int k=-1,i=0;
    while(i<Len-1)
    {
        if(k==-1||c[i]==c[k]){
            k++,i++;
            if(c[i]!=c[k])
                nxt[i]=k;
            else
                nxt[i]=nxt[k];
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
            i=i-j+1;
            j=0;
        }
    }
    return cnt;
}

int main()
{
    //freopen("data.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",&c2,&c1);
        GetNext(c2);
        int ans=kmp(c1,c2);
        printf("%d\n",ans);
    }
    return 0;
}

