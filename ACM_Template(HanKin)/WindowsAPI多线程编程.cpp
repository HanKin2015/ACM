#include <windows.h>
#include <stdio.h>
#include <iostream>

DWORD WINAPI myfun1(LPVOID lpParameter); //声明线程函数
DWORD WINAPI myfun2(LPVOID lpParameter);

using namespace std;

int main(int argc, _TCHAR* argv[])
{
    HANDLE h1,h2;//声明句柄变量
    h1=CreateThread(NULL,0,myfun1,NULL,0,NULL);//创建线程1
    cout<<"线程1开始运行！\n"<<endl;
    h2=CreateThread(NULL,0,myfun2,NULL,0,NULL);//创建线程2
    cout<<"线程2开始运行！"<<endl;

    //关闭线程句柄对象
    CloseHandle(h1);
    CloseHandle(h2);

    int n=0;
    while (1) {
        //cout<<"测试是不是循环重复执行"<<n++<<endl;
        if (getchar()=='q') { //如果用户输入字符q
            return 0;//程序正常退出
        } else {
            Sleep(100);//程序睡眠
        }
    }
}

//分别实现线程函数，并返回值
DWORD WINAPI myfun1(LPVOID lpParameter)
{
    cout<<"线程1正在运行"<<endl;
    return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
    cout<<"线程2正在运行"<<endl;
    return 0;
}
