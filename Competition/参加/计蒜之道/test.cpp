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
    char c = 'гд';
    string s = string(c);
    cout << s << endl;
    string str = "гд";
    char ch = 'd';
    if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << c <<endl;
    cout << str << endl;
    cout << ch << endl;
	return 0;
}
