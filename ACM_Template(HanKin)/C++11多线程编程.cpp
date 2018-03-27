#include <iostream>
#include <thread>
using namespace std;

thread::id main_thread_id = this_thread::get_id();

void hello()
{
    cout << "Hello Concurrent World\n";
    if (main_thread_id == this_thread::get_id())
        cout << "This is the main thread.\n";
    else
        cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
    this_thread::sleep_for(chrono::seconds(n));
    cout << "pause of " << n << " seconds ended\n";
}

int main() {
    thread t(hello);
    cout << t.hardware_concurrency() << endl;//���Բ���ִ�ж��ٸ�(��׼ȷ)
    cout << "native_handle " << t.native_handle() << endl;//���Բ���ִ�ж��ٸ�(��׼ȷ)
    t.join();
    thread a(hello);
    a.detach();
    thread threads[5];                         // Ĭ�Ϲ����߳�

    cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; ++i)
        threads[i] = thread(pause_thread, i + 1);   // move-assign threads
    cout << "Done spawning threads. Now waiting for them to join:\n";
    for (auto &thread : threads)
        thread.join();
    cout << "All threads joined!\n";
    return 0;
}
