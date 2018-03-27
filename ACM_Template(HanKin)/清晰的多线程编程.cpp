/*
https://blog.csdn.net/dcrmg/article/details/53912941
*/
#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;

mutex mu;  //线程互斥对象
int totalNum = 10;

//定义带参数子线程
void thread01(int num)
{
    for (int i = 0; i < num; i++) {
        cout << "Thread 01 is working ！" << endl;
        Sleep(100);
    }
    return;
}

//定义不带参数子线程
void thread02()
{
    for (int i = 0; i < 5; i++) {
        cout << "Thread 02 is working ！" << endl;
        Sleep(200);
    }
    return;
}

void thread03()
{
    while (totalNum > 0) {
        mu.lock(); //同步数据锁
        cout << "thread03 " << totalNum << endl;
        totalNum--;
        Sleep(100);
        mu.unlock();  //解除锁定
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
    *两个子线程并行执行，join函数会阻塞主流程，所以子线程都执行完成之后才继续执行主线程。
    *可以使用detach将子线程从主流程中分离，独立运行，不会阻塞主线程。
    *个人感觉默认是detach模式。
    */
    thread task01(thread01, 5);   //带参数子线程
    thread task02(thread02);
    //task01.join();
    //task02.join();
    //task01.detach();
    //task02.detach();

    for (int i = 0; i < 5; i++) {
        cout << "Main thread is working ！" << endl;
        Sleep(200);
    }
    /*
    *有两个问题，一是有很多变量被重复输出了，而有的变量没有被输出；二是正常情况下每个线程输出的数据
     后应该紧跟一个换行符，但这里大部分却是另一个线程的输出。

    *这是由于第一个线程对变量操作的过程中，第二个线程也对同一个变量进行各操作，导致第一个线程处理完
     后的输出有可能是线程二操作的结果。针对这种数据竞争的情况，可以使用线程互斥对象mutex保持数据同步。
    */
    thread task03(thread03);
    thread task04(thread04);
    task03.detach();
    task04.detach();
    system("pause");
}
