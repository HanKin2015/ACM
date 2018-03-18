#include <string.h>
#include <iostream>
using namespace std;

int t,n;
char tmp[26],c[1000005],fir,sec;

int main()
{
    cin>>t;
    while(t--){
        for(int i=0;i<26;i++)
            tmp[i]='A'+i;
        cin>>c;
        cin>>n;
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
                cout<<tmp[c[i]-'A'];
            else
                cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
