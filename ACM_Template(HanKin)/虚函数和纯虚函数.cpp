#include <iostream>
using namespace std;

class A
{
public:
    virtual void out1() = 0;  //������ʵ��
    virtual ~A(){};
    virtual void out2() { //Ĭ��ʵ��
        cout<<"A(out2)"<<endl;
    }
    void out3() {   //ǿ��ʵ��
        cout<<"A(out3)"<<endl;
    }
};

class B: public A
{
public:
    virtual ~B() {};
    void out1() {
        cout<<"B(out1)"<<endl;
    }
    void out2() {
        cout<<"B(out2)"<<endl;
    }
    void out3() {
        cout<<"B(out3)"<<endl;
    }
};

int main()
{
    A* a = new A;

    A *ab=new B;
    ab->out1();
    ab->out2();
    ab->out3();
    cout<<"************************"<<endl;
    B *bb=new B;
    bb->out1();
    bb->out2();
    bb->out3();

    delete ab;
    delete bb;
    return 0;
}
