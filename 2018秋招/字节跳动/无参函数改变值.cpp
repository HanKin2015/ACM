/*
通过无参函数pass，然后第二次输出x的值为456。
*/
#include <bits/stdc++.h>
using namespace std;

void pass(int n)
{
    //cout << 456 << endl;
    //exit(0);
    int temp;
    //cout << &temp << endl;
    int *p = &temp;
    *(p + n) = 456;
    return;
}

int main()
{
    int x = 123;
    //cout << &x << endl;
    cout << x << endl;
    for (int i = -100; i < 100; i++) {   // 对了不能来计算，因为这样又有了多个int数据
        pass(i);
        cout << i << ' ' << x << endl;
        if (x == 456) break;
    }
    return 0;
}

/* 不明白其中的道理
//通过无参函数pass，然后第二次输出x的值为456。
#include <bits/stdc++.h>
using namespace std;

void pass()
{
    int temp;
    int *p = &temp;
    cout << (p + 13) << endl;
    *(p + 13) = 456;
    return;
}

int main()
{
    int x = 123;
    //cout << &x << endl;
    cout << x << endl;
    pass();
    cout << x << endl;
    return 0;
}
*/
