#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define LL long long
#define maxn 10005
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int x[] = {3, 4, 1, 6, 2};
    int y[] = {3, 4, 1, 6, 2};
    for(int i = 0; i < 5; i++) {
        m.insert(make_pair(x[i], y[i]));
    }
    for(pair<int, int> p : m) {
        cout << p.first << ' ' << p.second << endl;
    }

    unordered_set<int> s;
    for(int i = 0; i < 5; i++) s.insert(x[i]);
    for(int i : s) cout << i << endl;
	return 0;
}
