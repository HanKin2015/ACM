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

int main()
{
    string str;
    while(cin >> str) {
        int len = str.size(), ans = 1;
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                if(j - i + 1 <= ans) continue;
                bool flag = true;
                for(int k = i; k <= j; k++) {
                    if(str[k] != str[j - k + i]) {
                        flag = false;
                    }
                }
                if(flag) ans = j - i + 1;
            }
        }
        cout << ans << endl;
    }
	return 0;
}
