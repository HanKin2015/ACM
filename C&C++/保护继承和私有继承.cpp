#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person(){ };//不加{}，编译器理解的不是函数定义，而是函数调用，所以说这个外部函数找不到。
    virtual ~Person() { cout << "~father" << endl; }
    int pub = 1;
    int getPro() {return pro;};
    int getPri() {return pri;};
    void play() {
        cout << "father" << endl;
    }
protected:
    int pro = 2;
private:
    int pri = 3;
};

class HanKin: public Person
{
public:
    void play() {
        cout << "son" << endl;
    }
    HanKin(){ };
    ~HanKin() { cout << "~son" << endl; };
};

int main()
{
    Person *per = new Person();
    cout << per->pub << endl;
    //cout << per->pro << endl;  外部（即main函数）初始化对象后，不能访问对象中的保护和私有成员。
    //cout << per->pri << endl;
    cout << per->getPro() << endl;  //这就体现了set和get方法的重要性
    cout << per->getPri() << endl;

    /*隐藏---就算父类和子类中的同名函数参数不同也不会有影响*/
    HanKin hankin;
    hankin.play();
    hankin.Person::play();  //继承时构造在前，析构则反过来

    /*isA只有一块内存，析构函数不一定是虚函数。删除指针后记得赋值空NULL*/
    delete per;
    per = NULL;
    cout << endl;
    Person *isa = new HanKin();  //要把前面的注释掉，加了virtual后虚函数，这样子类才会释放空间
    delete isa;
    //临时参数也会调用析构函数
    return 0;
}
