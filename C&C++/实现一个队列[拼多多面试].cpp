#include <bits/stdc++.h>
using namespace std;

template<typename T>
class QUEUE
{
public:
    QUEUE() {
        l = 0;
        r = 0;
    };
    virtual ~QUEUE() {

    }
    T front() {
        return this->arr[0];
    }
    void push(T x) {
        /*
        固定大小的数组，注意内存的循环利用
        逗逼的动态分配，每次在原来的基础上扩充时，先分配，后复制过去
        */
        arr = new T[1];
        this->arr[0] = x;
    }
    void pop() {

    }
    int size() {

    }
    bool empty() {

    }

public:
    // 模板类这里不能用private修饰
    T* arr;
    int l, r;
};

class temp
{
    int val;
};

int main()
{
    QUEUE<string> Q;
    Q.push("23333");
    cout << Q.front() << endl;

    temp<int> P;
    return 0;
}
