#include <bits/stdc++.h>
#define LL long long
#define maxn 1000005
using namespace std;

int arr[maxn] = { 0 };

int main()
{
    //堆和栈能分配的数组空间区别很大
    clock_t tim = clock();
    for(int i = 0; i < 2; i++) {
        vector<int> v;
        for(int j = 0; j < maxn; j++) v.push_back(j);
        v.clear();  //结论：清理了容器内存速度变快了
    }
    cout << "多次使用容器是否需要清理 = " << clock() - tim << endl;

    tim = clock();
    vector<int> mtk(maxn);
    for(int i = 0; i < maxn; i++) {
        if(mtk[i] == 0) mtk[i] = 1;
    }
    mtk.clear();
    cout << "vector判断使用 = " << clock() - tim << endl;

    tim = clock();
    map<int, int> mmp;
    for(int i = 0; i < maxn; i++) {
        if(mmp[i] == 0) mmp[i] = 1;
    }
    cout << "map判断使用 = " << clock() - tim << endl;

    tim = clock();
    map<int, int> md;
    for(int i = 0; i < maxn; i++) {
        md[i] = 1;
    }
    cout << "map插入使用 = " << clock() - tim << endl;

    tim = clock();
    unordered_map<int, int> unmap;
    for(int i = 0; i < maxn; i++) {
        if(unmap[i] == 0) unmap[i] = 1;
    }
    cout << "unordered_map判断使用 = " << clock() - tim << endl;

    tim = clock();

    for(int i = 0; i < maxn; i++) {
        if(arr[i] == 0) arr[i] = 1;
    }
    cout << "array判断使用 = " << clock() - tim << endl;

    tim = clock();
    set<int> see;
    for(int i = 0; i < maxn; i++) {
        see.insert(i);
    }
    cout << "set插入使用 = " << clock() - tim << endl;

    tim = clock();
    list<int> lis1;
    for(int i = 0; i < maxn; i++) {
        lis1.push_back(i);
    }
    cout << "list尾插入使用 = " << clock() - tim << endl;

    tim = clock();
    list<int> lis2;
    for(int i = 0; i < maxn; i++) {
        lis2.push_front(i);
    }
    cout << "list头插入使用 = " << clock() - tim << endl;

    tim = clock();
    unordered_set<int> unset;
    for(int i = 0; i < maxn; i++) {
        unset.insert(i);
    }
    cout << "unordered_set插入使用 = " << clock() - tim << endl;

    tim = clock();
    map<int, int> mdzz;
    for(int i = 0; i < maxn; i++) {
        auto it = mdzz.find(i);
        if(it == mdzz.end()) mdzz.insert(pair<int, int>(i, i));   //1000左右
    }
    cout << "map自己的成员函数find查找 = " << clock() - tim << endl;

    tim = clock();
    set<int> seed;
    for(int i = 0; i < maxn; i++) {
        set<int>::iterator it = seed.find(i);
        if(it == seed.end()) seed.insert(i);
    }
    cout << "set自己的成员函数find查找 = " << clock() - tim << endl;

    tim = clock();
    cout << endl << "stl中的find函数是线性时间查找的，所以尽量少用(对容器要求低，有自增就可以)，就是简单的遍历一遍" << endl;
    vector<int> lis;
    for(int i = 0; i < maxn; i++) {
        auto it = find(lis.begin(), lis.end(), i);
        if(i % 10000 == 0) cout << 3 << endl;
        if(it == lis.end()) lis.push_back(i);
    }
    cout << "list利用stl中的find查找 = " << clock() - tim << endl;

    tim = clock();
    vector<int> v_find;
    for(int i = 0; i < maxn; i++) {
        auto it = find(v_find.begin(), v_find.end(), i);
        if(i % 10000 == 0) cout << 2 << endl;
        if(it == v_find.end()) v_find.push_back(i);
    }
    cout << "vector查找 = " << clock() - tim << endl;

    tim = clock();
    set<int> sed;
    for(int i = 0; i < maxn; i++) {
        set<int>::iterator it = find(sed.begin(), sed.end(), i);
        if(i % 10000 == 0) cout << 1 << endl;
        if(it == sed.end()) sed.insert(i);
    }
    cout << "set判断使用 = " << clock() - tim << endl; //查找是真的慢

    map<int, int> m;
    cout << m[2] << endl;
    for(int i = 0; i < 4; i++) {
        vector<int> v(10);
        int a[10] = {0}, b[10];
        if(i == 2) a[2] = 1, b[2] = 1, v[2] = 1;
        cout << a[2] << " " << b[2] << " " << v[2]<< endl;
    }
	return 0;
}
