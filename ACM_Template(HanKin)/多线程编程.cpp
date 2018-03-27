/*
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg)
pthread_exit (status)
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h> //�����ͷ�ļ�POSIX

using namespace std;

#define NUM_THREADS 5  //5���߳�

struct thread_data { //ͨ���ṹ�崫�ݶ������
    int  thread_id;   //id
    char *message;    //��Ϣ
};

void *PrintHello(void *threadarg)  //�̵߳����к���
{
    struct thread_data *my_data;    //��Ȥ��ǰ���struct��Ҫ�ɲ�Ҫ
    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID : " << my_data->thread_id ;
    cout << " Message : " << my_data->message << endl;
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t threads[NUM_THREADS];  // �����̵߳� id �������������ʹ������
    struct thread_data td[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++ ) {
        cout <<"main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char*)"This is message";
        //���������ǣ��������߳�id���̲߳��������õĺ���������ĺ�������
        int ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
        if (ret) {
            cout << "Error:unable to create thread," << ret << endl;
            //exit(-1);
            return -1;
        }
    }
    //��֪��Ϊ�λ��������������˺���˵�Ļ�
    //pthread_exit(NULL); //�ȸ����߳��˳��󣬽��̲Ž������������ǿ�ƽ����ˣ��߳̿��ܻ�û��Ӧ������
    return 0;
}
