#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define maxn 10005
using namespace std;

int Number(char ch) {
    if(ch == 'A') return 10;
    if(ch == 'B') return 11;
    if(ch == 'C') return 12;
    if(ch == 'D') return 13;
    if(ch == 'E') return 14;
    if(ch == 'F') return 15;
    return int(ch - '0');
}

int main()
{
    string s;
    while(cin >> s) {
        LL temp = 1, ans = 0;
        for(int i = s.size() - 1; i >= 2; i--) {
            ans += Number(s[i]) * temp;
            temp *= 16;
        }
        cout << ans << endl;
    }
	return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin>>hex>>a){
    cout<<a<<endl;
    }
}
*/
