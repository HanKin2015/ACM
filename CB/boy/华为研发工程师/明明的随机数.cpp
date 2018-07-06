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
    set<int> s;
    int n;
    while(cin >> n) {
        int temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            s.insert(temp);
        }
        for(int i : s) cout << i << endl;
        s.clear();
    }
	return 0;
}

/*
#include <iostream>
using namespace std;
int main() {
    int N, n;
    while (cin >> N) {
        int a[1001] = { 0 };
        while (N--) {
            cin >> n;
            a[n] = 1;
        }
        for (int i = 0; i < 1001; i++)
            if (a[i])
                cout << i << endl;
    }
    return 0;
}
*/
