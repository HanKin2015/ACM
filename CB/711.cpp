#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == 'A' && s[i + 1] == 'C') {
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
