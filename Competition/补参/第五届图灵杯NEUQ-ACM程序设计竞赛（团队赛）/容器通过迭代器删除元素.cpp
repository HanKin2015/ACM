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

void dfs(vector<int> &a, int arr[], int dex)
{
    if(dex < 0) return;
    dfs(a, arr, dex - 1);
    return;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    int arr[505];
    dfs(a, arr, 5);
    cout << a.size() << endl;

    //���ɾ�����һ��Ԫ�ؾͻᱨ��
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);  //������������ʱ��Ҳ��������⣬����ɾ���ɾ�
    v.push_back(1);
    v.push_back(3);

    for(vector<int>::iterator it = v.begin(); it < v.end();it++) cout << *it << ' ';
    cout << endl;

    for(vector<int>::iterator it = v.begin(); it < v.end();it++) {
        if(*it == 3) v.erase(it);
        //else ;
    }

    for(vector<int>::iterator it = v.begin(); it != v.end();it++) {
        if(*it == 2) v.erase(it);
        //else ;
    }
    for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	return 0;
}
