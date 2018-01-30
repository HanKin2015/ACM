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
		//uint64_t��long long �ͣ���lld��I64d��ͬϵͳ��һ��.data������ʹ��
		printf("%lld %s  %lld %s\n", lhs.first, lhs.second.data(), rhs.first, rhs.second.data());
		//printf("%s\n", lhs.second.data());
		cout << lhs.second << ' ' << rhs.second << endl;
		return (lhs.first > rhs.first) or (not(lhs.first > rhs.first) and lhs.second < rhs.second);
	}
};
set<pair<uint64_t, Item>, decreasing_order_comparator> items_ordered_by_frequency;

int main()
{
	//������һ���ϣ����˵ڶ����糿�Ż�Ȼ����
	items_ordered_by_frequency.insert({ 5, "B" });
	items_ordered_by_frequency.insert({ 3, "A" });

	items_ordered_by_frequency.insert({ 2, "H" });
	items_ordered_by_frequency.insert({ 1, "T" });
	set<pair<uint64_t, Item>, decreasing_order_comparator>::iterator it = items_ordered_by_frequency.begin();
	cout << it->first << ' ' << it->second << endl;
    return 0;
}

