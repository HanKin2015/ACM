#include <iostream>
#include <string>
#include <set>
#include <iso646.h>
using namespace std;

typedef string Item;

// order items by decreasing frequency
struct decreasing_order_comparator {
	bool operator() (const pair<uint64_t, Item>& lhs, const pair<uint64_t, Item>& rhs) const
	{
		//uint64_t是long long 型，用lld或I64d不同系统不一样.data函数的使用
		printf("%lld %s  %lld %s\n", lhs.first, lhs.second.data(), rhs.first, rhs.second.data());
		//printf("%s\n", lhs.second.data());
		cout << lhs.second << ' ' << rhs.second << endl;
		return (lhs.first > rhs.first) or (not(lhs.first > rhs.first) and lhs.second < rhs.second);
	}
};
set<pair<uint64_t, Item>, decreasing_order_comparator> items_ordered_by_frequency;

int main()
{
	//调试了一晚上，到了第二天早晨才恍然大悟
	items_ordered_by_frequency.insert({ 5, "B" });
	items_ordered_by_frequency.insert({ 3, "A" });

	items_ordered_by_frequency.insert({ 2, "H" });
	items_ordered_by_frequency.insert({ 1, "T" });
	set<pair<uint64_t, Item>, decreasing_order_comparator>::iterator it = items_ordered_by_frequency.begin();
	cout << it->first << ' ' << it->second << endl;
    return 0;
}

