#include <iostream>
#include <string>
using namespace std;
/**
 * �����ࣺStudent
 * ���ݳ�Ա��m_strName
 * �޲ι��캯����Student()
 * �вι��캯����Student(string _name)
 * �������캯����Student(const Student& stu)
 * ����������~Student()
 * ���ݳ�Ա������setName(string _name)��getName()
 */

class Student
{
public:
    string m_strName;
    Student(){};

private:
    Student(string _name){};
    Student(const Student& stu){};
    ~Student(){};
    void setName(string _name){
        m_strName = _name;
    }
    string getName(){
        return m_strName;
    }
};

int main(void)
{
    // ͨ��new��ʽʵ��������*stu
    Student *stu = new Student();
    // ���Ķ�������ݳ�ԱΪ��Ľ������
	stu->setName("Ľ����");
    // ��ӡ��������ݳ�Ա
	cout << stu->m_strName << endl;
	return 0;
}
