#include <bits/stdc++.h>
#define LL long long
#define maxn 1000005
using namespace std;

int arr[maxn] = { 0 };

int main()
{
    //�Ѻ�ջ�ܷ��������ռ�����ܴ�
    clock_t tim = clock();
    for(int i = 0; i < 2; i++) {
        vector<int> v;
        for(int j = 0; j < maxn; j++) v.push_back(j);
        v.clear();  //���ۣ������������ڴ��ٶȱ����
    }
    cout << "���ʹ�������Ƿ���Ҫ���� = " << clock() - tim << endl;

    tim = clock();
    vector<int> mtk(maxn);
    for(int i = 0; i < maxn; i++) {
        if(mtk[i] == 0) mtk[i] = 1;
    }
    mtk.clear();
    cout << "vector�ж�ʹ�� = " << clock() - tim << endl;

    tim = clock();
    map<int, int> mmp;
    for(int i = 0; i < maxn; i++) {
        if(mmp[i] == 0) mmp[i] = 1;
    }
    cout << "map�ж�ʹ�� = " << clock() - tim << endl;

    tim = clock();
    map<int, int> md;
    for(int i = 0; i < maxn; i++) {
        md[i] = 1;
    }
    cout << "map����ʹ�� = " << clock() - tim << endl;

    tim = clock();
    unordered_map<int, int> unmap;
    for(int i = 0; i < maxn; i++) {
        if(unmap[i] == 0) unmap[i] = 1;
    }
    cout << "unordered_map�ж�ʹ�� = " << clock() - tim << endl;

    tim = clock();

    for(int i = 0; i < maxn; i++) {
        if(arr[i] == 0) arr[i] = 1;
    }
    cout << "array�ж�ʹ�� = " << clock() - tim << endl;

    tim = clock();
    set<int> see;
    for(int i = 0; i < maxn; i++) {
        see.insert(i);
    }
    cout << "set����ʹ�� = " << clock() - tim << endl;

    tim = clock();
    list<int> lis1;
    for(int i = 0; i < maxn; i++) {
        lis1.push_back(i);
    }
    cout << "listβ����ʹ�� = " << clock() - tim << endl;

    tim = clock();
    list<int> lis2;
    for(int i = 0; i < maxn; i++) {
        lis2.push_front(i);
    }
    cout << "listͷ����ʹ�� = " << clock() - tim << endl;

    tim = clock();
    unordered_set<int> unset;
    for(int i = 0; i < maxn; i++) {
        unset.insert(i);
    }
    cout << "unordered_set����ʹ�� = " << clock() - tim << endl;

    tim = clock();
    map<int, int> mdzz;
    for(int i = 0; i < maxn; i++) {
        auto it = mdzz.find(i);
        if(it == mdzz.end()) mdzz.insert(pair<int, int>(i, i));   //1000����
    }
    cout << "map�Լ��ĳ�Ա����find���� = " << clock() - tim << endl;

    tim = clock();
    set<int> seed;
    for(int i = 0; i < maxn; i++) {
        set<int>::iterator it = seed.find(i);
        if(it == seed.end()) seed.insert(i);
    }
    cout << "set�Լ��ĳ�Ա����find���� = " << clock() - tim << endl;

    tim = clock();
    cout << endl << "stl�е�find����������ʱ����ҵģ����Ծ�������(������Ҫ��ͣ��������Ϳ���)�����Ǽ򵥵ı���һ��" << endl;
    vector<int> lis;
    for(int i = 0; i < maxn; i++) {
        auto it = find(lis.begin(), lis.end(), i);
        if(i % 10000 == 0) cout << 3 << endl;
        if(it == lis.end()) lis.push_back(i);
    }
    cout << "list����stl�е�find���� = " << clock() - tim << endl;

    tim = clock();
    vector<int> v_find;
    for(int i = 0; i < maxn; i++) {
        auto it = find(v_find.begin(), v_find.end(), i);
        if(i % 10000 == 0) cout << 2 << endl;
        if(it == v_find.end()) v_find.push_back(i);
    }
    cout << "vector���� = " << clock() - tim << endl;

    tim = clock();
    set<int> sed;
    for(int i = 0; i < maxn; i++) {
        set<int>::iterator it = find(sed.begin(), sed.end(), i);
        if(i % 10000 == 0) cout << 1 << endl;
        if(it == sed.end()) sed.insert(i);
    }
    cout << "set�ж�ʹ�� = " << clock() - tim << endl; //�����������

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
