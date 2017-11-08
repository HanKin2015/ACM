#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argv) {
    srand((unsigned)time(NULL));  // 随机数根据时间不同而不同
//    for(int i = 0; i < 100; i++)
//        cout << rand()%100+1 << endl;
    cout << rand(0,10) << endl;
    return 0;
}
