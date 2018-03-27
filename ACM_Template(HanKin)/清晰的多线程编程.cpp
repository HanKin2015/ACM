/*
https://blog.csdn.net/dcrmg/article/details/53912941
*/
#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;

mutex mu;  //�̻߳������
int totalNum = 10;

//������������߳�
void thread01(int num)
{
    for (int i = 0; i < num; i++) {
        cout << "Thread 01 is working ��" << endl;
        Sleep(100);
    }
    return;
}

//���岻���������߳�
void thread02()
{
    for (int i = 0; i < 5; i++) {
        cout << "Thread 02 is working ��" << endl;
        Sleep(200);
    }
    return;
}

void thread03()
{
    while (totalNum > 0) {
        mu.lock(); //ͬ��������
        cout << "thread03 " << totalNum << endl;
        totalNum--;
        Sleep(100);
        mu.unlock();  //�������
    }
    return;
}
void thread04()
{
    while (totalNum > 0) {
        mu.lock();
        cout << "thread04 " << totalNum << endl;
        totalNum--;
        Sleep(100);
        mu.unlock();
    }
    return;
}

int main()
{
    /*
    *�������̲߳���ִ�У�join���������������̣��������̶߳�ִ�����֮��ż���ִ�����̡߳�
    *����ʹ��detach�����̴߳��������з��룬�������У������������̡߳�
    *���˸о�Ĭ����detachģʽ��
    */
    thread task01(thread01, 5);   //���������߳�
    thread task02(thread02);
    //task01.join();
    //task02.join();
    //task01.detach();
    //task02.detach();

    for (int i = 0; i < 5; i++) {
        cout << "Main thread is working ��" << endl;
        Sleep(200);
    }
    /*
    *���������⣬һ���кܶ�������ظ�����ˣ����еı���û�б�������������������ÿ���߳����������
     ��Ӧ�ý���һ�����з���������󲿷�ȴ����һ���̵߳������

    *�������ڵ�һ���̶߳Ա��������Ĺ����У��ڶ����߳�Ҳ��ͬһ���������и����������µ�һ���̴߳�����
     �������п������̶߳������Ľ��������������ݾ��������������ʹ���̻߳������mutex��������ͬ����
    */
    thread task03(thread03);
    thread task04(thread04);
    task03.detach();
    task04.detach();
    system("pause");
}
