#include <windows.h>
#include <stdio.h>
#include <iostream>

DWORD WINAPI myfun1(LPVOID lpParameter); //�����̺߳���
DWORD WINAPI myfun2(LPVOID lpParameter);

using namespace std;

int main(int argc, _TCHAR* argv[])
{
    HANDLE h1,h2;//�����������
    h1=CreateThread(NULL,0,myfun1,NULL,0,NULL);//�����߳�1
    cout<<"�߳�1��ʼ���У�\n"<<endl;
    h2=CreateThread(NULL,0,myfun2,NULL,0,NULL);//�����߳�2
    cout<<"�߳�2��ʼ���У�"<<endl;

    //�ر��߳̾������
    CloseHandle(h1);
    CloseHandle(h2);

    int n=0;
    while (1) {
        //cout<<"�����ǲ���ѭ���ظ�ִ��"<<n++<<endl;
        if (getchar()=='q') { //����û������ַ�q
            return 0;//���������˳�
        } else {
            Sleep(100);//����˯��
        }
    }
}

//�ֱ�ʵ���̺߳�����������ֵ
DWORD WINAPI myfun1(LPVOID lpParameter)
{
    cout<<"�߳�1��������"<<endl;
    return 0;
}

DWORD WINAPI myfun2(LPVOID lpParameter)
{
    cout<<"�߳�2��������"<<endl;
    return 0;
}
