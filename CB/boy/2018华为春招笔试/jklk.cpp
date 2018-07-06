#include <bits/stdc++.h>
using namespace std;

void f1(int *p)
{
    int n = 10;
    *p = n;
    //p = &n;  好奇怪，这样是错误的。指针p由原来指向c改成了n，所以没有改变c了。
    return;
}

void f2(int &p)
{
    int n = 100;
    p = n;
    return;
}

int main()
{
    //交集
    set<int> set1, set2, set3;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set2.insert(5);
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);

    vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(2);
    v2.insert(v2.begin(), v1.begin(), v1.end());
    v2.push_back(3);
    v3.insert(v3.end(), v1.begin(), v1.end());
    v3.insert(v3.end(), v2.begin(), v2.end());
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    v3.assign(v1.begin(), v1.end());
    for(int i : v3) cout << i << ' ';
    cout << endl;

    https://blog.csdn.net/weiwenhp/article/details/8691463
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
    set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(RUnion,RUnion.begin()));
    set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(RDiff1,RDiff1.begin()));
    set_difference(B.begin(),B.end(),A.begin(),A.end(),inserter(RDiff2,RDiff2.begin()));
    对称差集set_symmetric_difference
对称差指只属于one或two,但不同时属于one和two的.实际上就是one和two的并集 与 one和two交集的 差集

retEndPos = set_symmetric_difference( one.begin(), one.end(), two.begin(), two.end() , result.begin());

result.resize( retEndPos - result.begin() ) ; //此时result中元素为 22 33 44 55
    //set3.insert(set3.begin(), set1.begin(), set1.end());
    cout << set3.size() << endl;
    //copy(set2.begin(), set2.end(), set3.end());
    cout << set3.size() << endl;
    for(int i : set3) cout << i << ' ';
    cout << endl;


    fstream file;
    file.open("fin.txt");
    while(!file.eof()){
        char str[256];
        file.getline(str, 256);
        cout << str << endl;
    }
    int k = 12;
    int temp = (k & -k);  //只留下最低位的1和其右边的0，高位的数字删除
    int tmp1 = k - (k & -k);  //很明显，把最低位的1变成0
    int tmp2 = k ^ (k & -k);

    cout << temp << endl;
    cout << tmp1 << ' ' << tmp2 << endl;

    int c = 1;
    cout << c << endl;
    f1(&c);
    cout << c << endl;
    f2(c);
    cout << c << endl;
    int *p = &c;
    return 0;
}

/*
5 = 101
12 = 1100
10 = 1010

*/
