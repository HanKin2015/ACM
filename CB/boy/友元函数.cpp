#include <iostream>
using namespace std;

/*
gcc中，在引用某个已经实现的类时：如果只是定义某个类的指针，可以使用class关键字先进行声明，
而不需包含头文件；但如果涉及到定义某个类的对象或是引用类的某个具体成员时，则必须包含该类的
头文件，并且不要加class关键字进行声明。否则，将会出现标题所示编译错误！

The solution is to follow the C++ pattern of the class declaration in a .h file and the function
bodies in a .cpp. That way all the declarations appear before the first definitions, and the
compiler knows what it's working with.
*/

class Match;  //声明类

class Time
{
public:
	friend void PrintTime(Time &t);
	friend void Match::CoutTime(Time &t);
	Time(int hour, int min, int sec) {
        m_iHour = hour;
        m_iMinute = min;
        m_iSecond = sec;
	}

private:
	int m_iHour;
	int m_iMinute;
	int m_iSecond;
};

class Match
{
public:
    void CoutTime(Time &t) {
        cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond << endl;
        return;
    }
};

void PrintTime(Time &t)
{
    cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond << endl;
    return;
}

int main()
{
    //Time *t = new Time(22, 4, 25);
    Time t(22, 4, 25);
    PrintTime(t);
	return 0;
}
