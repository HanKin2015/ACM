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
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&threads[i], NULL, PrintHello, NULL);
        if (ret) {
            cout << "Error:unable to create thread," << ret << endl;
            return -1;
        }
    }
    //如果这句代码不写的话就只会看到start语句，加了就能看到over
    pthread_exit(NULL); //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    cout << "OK?" << endl;
    system("pause");
    return 0;
}

