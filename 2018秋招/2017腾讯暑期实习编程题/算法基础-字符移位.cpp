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
        for(int i = 0; i < str.size(); i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                int j = i - 1;
                while(str[j] >= 'A' && str[j] <= 'Z' && j >= 0) {
                    swap(str[j], str[j + 1]);
                    j--;
                }
            }
        }
        cout << str << endl;
    }
	return 0;
}
