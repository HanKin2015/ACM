/*
只写get函数而不写set函数来实现只读
非只读：
void setScore(int_score)
{
    m_iScore=_score;
}
int getScore()
{
    return m_iScore;
}
只读：
int getScore()
{
    return m_iScore;
}
*/
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    void setName(string _name)
    {
        m_strName = _name;
    }
    string getName()
    {
        return m_strName;
    }
    void setGender(string _gender)
    {
        m_strGender = _gender;
    }
    string getGender()
    {
        return m_strGender;
    }
    int getScore()
    {
        return m_iScore;
    }
    void initScore()
    {
        m_iScore = 0;
    }
    void study(int _score)
    {
        m_iScore+=_score;//m_iScore=m_iScore+_score;
    }

private:
    string m_strName;
    string m_strGender;
    int m_iScore;
};

int main(void)
{
    Student stu;
    stu.initScore();
    stu.setName("zhangsan");
    stu.setGender("男");
    stu.study(5);
    stu.study(3);

    cout << stu.getName() << " " << stu.getGender() << " " << stu.getScore() <<endl;
    return 0;
}
