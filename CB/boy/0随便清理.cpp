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
        //ǰ����string���ͣ������������±�Ϊ0��1��ǰ�涼��0�����һ����1�����������ո������һ��ʷ�����⡣
        printf("%d%c", i, " \t"[i == 4]);
	}
	cout << "hejian" << endl;
	for(int i = 0; i < 5; i++) {
        printf("%d%c", i, ' ');
        //printf("%d%c", i, " ");  �ᱨ����Ȼ���򣡣���
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
