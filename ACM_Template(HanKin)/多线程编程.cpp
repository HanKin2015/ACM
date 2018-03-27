/*
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg)
pthread_exit (status)
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h> //必须的头文件POSIX

using namespace std;

#define NUM_THREADS 5  //5个线程

struct thread_data { //通过结构体传递多个参数
    int  thread_id;   //id
    char *message;    //信息
};

void *PrintHello(void *threadarg)  //线程的运行函数
{
    struct thread_data *my_data;    //有趣，前面的struct可要可不要
    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID : " << my_data->thread_id ;
    cout << " Message : " << my_data->message << endl;
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t threads[NUM_THREADS];  // 定义线程的 id 变量，多个变量使用数组
    struct thread_data td[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++ ) {
        cout <<"main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char*)"This is message";
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
        if (ret) {
            cout << "Error:unable to create thread," << ret << endl;
            //exit(-1);
            return -1;
        }
    }
    //不知道为何会程序崩溃，明白了后面说的话
    //pthread_exit(NULL); //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    return 0;
}
