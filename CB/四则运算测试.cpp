#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argv) {
    srand((unsigned)time(NULL));  // ���������ʱ�䲻ͬ����ͬ
//    for(int i = 0; i < 100; i++)
//        cout << rand()%100+1 << endl;
    cout << rand(0,10) << endl;
    return 0;
}
