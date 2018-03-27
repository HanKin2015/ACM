#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *args)
{
    cout << "Thread Start" << endl;
    int cnt = 0;
    for(int i = 0; i < 1e9; i++) cnt++;
    cout << "Thread Over!" << cnt << endl;
    pthread_exit(NULL);
}

void SayHello()
{
    cout << "Say Start" << endl;
    int cnt = 0;
    for(int i = 0; i < 1e9; i++) cnt++;
    cout << "Say Over!" << endl;
    return;
}

int main(int argc, char **argv)
{
    for(int i = 0; i < NUM_THREADS; i++) {
        SayHello();
    }
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++ ) {
        //���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������
        int ret = pthread_create(&threads[i], NULL, PrintHello, NULL);
        if (ret) {
            cout << "Error:unable to create thread," << ret << endl;
            return -1;
        }
    }
    //��������벻д�Ļ���ֻ�ῴ��start��䣬���˾��ܿ���over
    pthread_exit(NULL); //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
    cout << "OK?" << endl;
    system("pause");
    return 0;
}

