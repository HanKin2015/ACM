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
        �̶���С�����飬ע���ڴ��ѭ������
        ���ƵĶ�̬���䣬ÿ����ԭ���Ļ���������ʱ���ȷ��䣬���ƹ�ȥ
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
    // ģ�������ﲻ����private����
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
