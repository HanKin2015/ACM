#include <iostream>
#include <hash_map>
using namespace std;
//using namespace stdext;
//#include <ext/hash_map>
using namespace __gnu_cxx;
//The include file <ext/hash_map> refers to the GNU extension hash map class and this is declared in namespace __gnu_cxx.

int main()
{
    hash_map<string, int> username;
    hash_map<string, int> email;
    int N;
    cin >> N;
    int dex = 20000;        //email`s starting point
    for(int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        if(username.find(temp) != username.end()) { //put username into integer
            username[temp] = i;     //every row input different username
        }
        int cnt;
        cin >> cnt;
        while(cnt--) {
            cin >> temp;
            if(email.find(temp) != email.end()) { //put email into integer
                email[temp] = dex;
                dex++;
            }

            int index[10005];  //
        }
    }
    for(int i = 1; i <= N; i++) {

    }
    return 0;
}
