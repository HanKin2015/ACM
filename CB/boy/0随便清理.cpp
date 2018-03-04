#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	list<int> l;
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	l.push_back(1);
	for(int i : l) cout << i << endl;
	//cout << l[2] << endl;
	for(int i = 0; i < 5; i++) {
        //前面是string类型，后面中括号下标为0或1，前面都是0，最后一个是1，解决了输出空格空行这一历史性难题。
        printf("%d%c", i, " \t"[i == 4]);
	}
	cout << "hejian" << endl;
	for(int i = 0; i < 5; i++) {
        printf("%d%c", i, ' ');
        //printf("%d%c", i, " ");  会报错，恍然大悟！！！
	}
	cout << "\thejian" << endl;

	list<pair<int, int> > ll;
	ll.push_back(make_pair(1,2));
	ll.push_back(make_pair(1,2));
	ll.push_back(make_pair(1,2));
	ll.push_back(make_pair(1,2));
	ll.push_back(make_pair(1,2));
	ll.push_back(make_pair(1,2));
	cout << ll.size() << endl;
	int t = -1;
	auto len = ll.size();
	if(len > t) cout << "ok" << endl;

	set<int>a;
    set<int>b;
    set<int>c;
    set<int>d;
    set<int>e;

    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);

    b.insert(3);
    b.insert(4);
    b.insert(5);

    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
    set<int>::iterator s;
    for(s=c.begin(); s!=c.end(); s++) {
        cout <<(*s)<<",";
    }
    cout << endl;

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(d, d.begin()));
    for(s=d.begin(); s!=d.end(); s++) {
        cout <<(*s) <<",";
    }
    cout << endl;

    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(e, e.begin()));
    for(s=e.begin(); s!=e.end(); s++) {
        cout <<(*s)<<",";
    }
    cout <<endl;
	return 0;
}
