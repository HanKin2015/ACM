#include <bits/stdc++.h>
using namespace std;

char* DeleteSpace(char* str)
{
    char* p = str, *q = str;
    int len = strlen(str);
    while (*q != '\0') {  // 指针字符串没有"\0"，但char数组有
        if (*q != ' ') {
            *p = *q;
            p++;
        }
        q++;
    }
    *p = '\0';
    return str;
}

#include <functional>
void PQueue()
{
    priority_queue<int, vector<int>, greater<int> > Q;   // 按照元素从小到大的顺序出队
    //priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> countMax;

    int A[] = {7, 5, 2, 1, 3, 4, 6};
    for (int i = 0; i < 7; i++) {
        Q.push(A[i]);
        int tmp = Q.top();
        cout << tmp << endl;
    }
    return;
}

int fun(int n)
{
    return n;
}

int main()
{
    assert(fun(5) == 6);

    int a[] = {2, 5, 6, 8, 3, 1, 4};
    sort(a, a + 7, greater<int>());    // 单调递减(后面的greater缺一不可)
    for (int i = 0; i < 7; i++) cout << a[i] << ' ';
    cout << endl;
    sort(a, a + 7, less<int>());       // 单调递增
    for (int i = 0; i < 7; i++) cout << a[i] << ' ';
    cout << endl;

    //assert(DeleteSpace("  he jian  ") == "hejian");
    //char* str = "  he jian  ";   // 不能写成指针字符串，指针不能对其值进行修改
    char str[] = "  he jian  ";
    cout << DeleteSpace(str) << endl;

    PQueue();
    return 0;
}
