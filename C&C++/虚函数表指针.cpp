#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    Shape(){ cout << "Shape" << endl; }
    ~Shape(){ cout << "~Shape" << endl; }; //�����������ź��治Ӧ���зֺ�
    virtual void test() { return; }
};

class Circle: public Shape
{
public:
    Circle(int r){ radius = r; };  //ע������ĸ�ֵ����Ҫд����
    ~Circle(){ cout << "~Circle" << endl; };
protected:
    int radius;
};

int main()
{
    Shape shape;  //���������麯���ͻ�����麯�����ͻ����麯��ָ�룬���Դ���4
    cout << sizeof(shape) << endl;  //1��Ϊ�˱���Լ��Ĵ��ڣ�����������ݣ����ݵ��ڴ����1����Լ��Ĵ��ڡ�
    int *p = (int *)&shape;
    cout << p << endl;

    Circle circle(100);
    cout << sizeof(circle) << endl;
    int *q = (int *)&circle;
    cout << q << endl;
    cout << (unsigned int)(*q) << endl;  //���鹹�б�ʱ���鹹ָ�����ڵĵ�ַ������׵�ַ������������鹹�б�ĵ�ַ
    q++;
    cout << (unsigned int)(*q) << endl;  //���麯����ʱ��ǰ��q�����100�������������100.

    return 0;
}
