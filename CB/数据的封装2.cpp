#include <iostream>
#include <string>
using namespace std;

/**
  * �����ࣺStudent
  * ���ݳ�Ա��m_strName
  * ���ݳ�Ա�ķ�װ������setName()��getName()
  */
class Student
{
public:
    // �������ݳ�Ա��װ����setName()
    void setName(string name)
    {
        m_strName = name;
    }


    // �������ݳ�Ա��װ����getName()
    string getName()
    {
        return m_strName;
    }


//����Student��˽�����ݳ�Աm_strName
private:
    string m_strName;

};

int main()
{
    // ʹ��new�ؼ��֣�ʵ��������
	Student *str = new Student();
    // ���ö�������ݳ�Ա
	str->setName("Ľ����");
    // ʹ��cout��ӡ����str�����ݳ�Ա
    cout << str->getName() << endl;
    // ������str���ڴ��ͷţ��������ÿ�
	delete str;
	str = NULL;
	return 0;
}
