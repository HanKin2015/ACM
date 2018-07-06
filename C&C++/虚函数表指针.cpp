#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    Shape(){ cout << "Shape" << endl; }
    ~Shape(){ cout << "~Shape" << endl; }; //有问题额，大括号后面不应该有分号
    virtual void test() { return; }
};

class Circle: public Shape
{
public:
    Circle(int r){ radius = r; };  //注意这里的赋值，不要写反了
    ~Circle(){ cout << "~Circle" << endl; };
protected:
    int radius;
};

int main()
{
    Shape shape;  //里面有了虚函数就会产生虚函数表，就会有虚函数指针，所以答案是4
    cout << sizeof(shape) << endl;  //1是为了标记自己的存在，如果有了数据，数据的内存替代1标记自己的存在。
    int *p = (int *)&shape;
    cout << p << endl;

    Circle circle(100);
    cout << sizeof(circle) << endl;
    int *q = (int *)&circle;
    cout << q << endl;
    cout << (unsigned int)(*q) << endl;  //有虚构列表时，虚构指针所在的地址是类的首地址，而输出的是虚构列表的地址
    q++;
    cout << (unsigned int)(*q) << endl;  //无虚函数表时，前面q结果是100，有了这里就是100.

    return 0;
}
