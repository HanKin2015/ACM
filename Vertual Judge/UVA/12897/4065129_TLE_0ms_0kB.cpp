#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int tmp[26];
        for(int i=0;i<26;i++)
            tmp[i]=i;
        char c[1000005];
        scanf("%s",&c);
        int n;
        scanf("%d",&n);
        char fir[10005],sec[10005];
        for(int i=0;i<n;i++){
            cin>>fir[i]>>sec[i];
            int l=fir[i]-'A',r=sec[i]-'A';
            for(int i=0;i<26;i++){
                if(tmp[i]==r){
                    tmp[i]=l;
                }
            }
        }
        for(int i=0;i<strlen(c);i++){
            if(c[i]!='_')
                c[i]=(char)(tmp[(c[i]-'A')]+'A');
        }
        printf("%s\n",c);
    }
    return 0;
}
