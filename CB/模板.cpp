#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <random>
#include <vector>
#include <map>
#define maxn 1005
#define LL long long
using namespace std;

void f1(vector<int> v) {
    cout << "容器";
    return;
}

void f2() {
    cout << "空";
    return;
}

void f3(int arr[]) {
    cout << "数组";
    return;
}


void f4(vector<int> &v) {
    cout << "容器引用";
    return;
}

void f5(vector<int> *v) {
    cout << "容器指针";
    return;
}
//数组参数本身就是地址，一般不会用在引用和指针上
void f6(int (&arr)[12]) {
    cout << "数组引用";
    return;
}

int arr[100000005];

int main()
{
    char str[15], ch[10];
    cin >> str;int n;
    cin >> n;
    string temp = "";
    cin >> ch;

    cout << str << endl;
    cout << ch << endl;
    //1、查看容器作为参数传递的是什么
    //2、栈和堆内存最大能开多少
    vector<int> v;
    for(int i = 0; i < 100000000; i++) {
        v.push_back(i);
        arr[i] = i;
    }
    clock_t tim = clock();
    f1(v);
    cout << clock() - tim << endl;
    tim = clock();
    f2();
    cout << clock() - tim << endl;
    tim = clock();
    f3(arr);
    cout << clock() - tim << endl;
    tim = clock();
    f4(v);
    cout << clock() - tim << endl;
    tim = clock();
    f5(&v);
    cout << clock() - tim << endl;
    cout << endl << endl;

    map<string, int> mmp;
    mmp["hejian"] = 222;
    //mmp.insert(map<string, int>::value_type ("hejian", 222));
    //mmp.insert(pair<string, int>("hejian", 222));
    cout << mmp["hejian"] << endl;
    cout << mmp["wanghe"] << endl;

    vector<int> v1, v2;
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(2);
    v2 = v1;
    cout << v2[2] << endl;
    v2.reserve(55);
    v2.resize(43);
    cout << v2.size() << endl;

    int t = 1;
    int seed = time(0); srand(seed);
    cout << rand() <<endl;   //返回一个[0,RAND_MAX]间的随机整数。
    cout << RAND_MAX << endl;
    int b = 100;
    t = 10;
    while(t--) {
        long long x = (double)rand() / (RAND_MAX + 1) * b;  //[0, b)间的随机整数
        x %= b;
        //if(x == 0 || x == 100)
            cout << x << endl;
        x = rand();
        //if(x == 0) cout << "hejian" << x << endl;
    }

    random_device rd;
    mt19937 mt_rd(rd());
    mt19937 mt(1729);
    mt19937 mt_time(time(0));
    uniform_int_distribution<int> dist(1, 100);  //[1, 100]间的随机整数
    t = 10000;
    while(t--) {
        int x = dist(mt_time);
        if(x == 0)
        cout << "mt" << x << endl;
    }
    return 0;
}
