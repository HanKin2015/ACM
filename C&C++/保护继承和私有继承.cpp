#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person(){ };//����{}�����������Ĳ��Ǻ������壬���Ǻ������ã�����˵����ⲿ�����Ҳ�����
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
    //cout << per->pro << endl;  �ⲿ����main��������ʼ������󣬲��ܷ��ʶ����еı�����˽�г�Ա��
    //cout << per->pri << endl;
    cout << per->getPro() << endl;  //���������set��get��������Ҫ��
    cout << per->getPri() << endl;

    /*����---���㸸��������е�ͬ������������ͬҲ������Ӱ��*/
    HanKin hankin;
    hankin.play();
    hankin.Person::play();  //�̳�ʱ������ǰ�������򷴹���

    /*isAֻ��һ���ڴ棬����������һ�����麯����ɾ��ָ���ǵø�ֵ��NULL*/
    delete per;
    per = NULL;
    cout << endl;
    Person *isa = new HanKin();  //Ҫ��ǰ���ע�͵�������virtual���麯������������Ż��ͷſռ�
    delete isa;
    //��ʱ����Ҳ�������������
    return 0;
}
