#include <string.h>
#include <iostream>
using namespace std;

int t,n;
char tmp[26],fir,sec;
string s;

int main()
{
    cin>>t;
    while(t--){
        for(int i=0;i<26;i++)
            tmp[i]='A'+i;
        cin>>s;
        cin>>n;
        while(n--){
            cin>>fir>>sec;
            for(int i=0;i<26;i++){
                if(tmp[i]==sec){
                    tmp[i]=fir;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='_')
                cout<<tmp[s[i]-'A'];
            else
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
