#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int tmp[26];
        for(int i=0;i<26;i++)
            tmp[i]=i;
        char c[1000005];
        cin>>c;
        int n;
        cin>>n;
        char fir[10005],sec[10005];
        for(int i=0;i<n;i++){
            cin>>fir[i]>>sec[i];
            int l=(int)(fir[i]-'A'),r=(int)(sec[i]-'A');
            for(int i=0;i<26;i++){
                if(tmp[i]==r){
                    tmp[i]=l;
                }
            }
        }
        for(int i=0;i<strlen(c);i++){
            if(c[i]!='_')
                c[i]=(char)(tmp[(int)(c[i]-'A')]+'A');
        }
        cout<<c<<endl;
    }
    return 0;
}
