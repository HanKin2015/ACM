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
    set<int> num;
    num.insert(2);
    num.insert(5);
    num.insert(12);
    cout << *num.begin()++ << endl;
    cout << *(++num.begin()) << endl;
    cout << *(--num.end()) << endl;
	return 0;
}
