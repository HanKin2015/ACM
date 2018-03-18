#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        char tmp[26];
        for(int i=0;i<26;i++)
            tmp[i]='A'+i;
        char c[1000005];
        cin>>c;
        int n;
        cin>>n;
        char fir,sec;
        while(n--){
            cin>>fir>>sec;
            for(int i=0;i<26;i++){
                if(tmp[i]==sec){
                    tmp[i]=fir;
                }
            }
        }
        for(int i=0;i<strlen(c);i++){
            if(c[i]!='_')
                c[i]=tmp[c[i]-'A'];
        }
        cout<<c<<endl;
    }
    return 0;
}
