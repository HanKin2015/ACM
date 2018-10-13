#include <iostream>
using namespace std;

/*
gcc�У�������ĳ���Ѿ�ʵ�ֵ���ʱ�����ֻ�Ƕ���ĳ�����ָ�룬����ʹ��class�ؼ����Ƚ���������
���������ͷ�ļ���������漰������ĳ����Ķ�������������ĳ�������Աʱ���������������
ͷ�ļ������Ҳ�Ҫ��class�ؼ��ֽ������������򣬽�����ֱ�����ʾ�������

The solution is to follow the C++ pattern of the class declaration in a .h file and the function
bodies in a .cpp. That way all the declarations appear before the first definitions, and the
compiler knows what it's working with.
*/

class Match;  //������

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
