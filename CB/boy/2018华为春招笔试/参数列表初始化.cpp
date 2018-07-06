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

class test {
public:
    test(int a):x(10), y(12) {}
    int x;
    int y;
};

int main()
{
    test *t = new test(2);
    cout << t->x << endl;
    cout << t->y << endl;

    map<string, int> m;
    m.insert(make_pair("he", 2));
    m["wang"] = 3;
    m["zhang"] = 2;
    cout << m["he"] << endl;
    cout << m["jian"] << endl;

    string word, keyword = "hjaKDHKASda";
	transform(keyword.begin(), keyword.end(), back_inserter(word), ::tolower);
	cout << word << endl;

	string invalid[] = { "and", "on", "or", "the", "of", "for", "a", "in" };
	int len = sizeof(invalid) / sizeof(string);
	cout << len << endl;

	string str = "hejian";
	str[str.size() - 1] = '\0';
	cout << str << endl;
	return 0;
}
