#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int calc(int a, char oper, int b) {
    if(oper == '+') {
        return a + b;
    }
    else if(oper == '-') {
        return a - b;
    }
    else if(oper == '*') {
        return a * b;
    }
    return a / b;
}

int main(int argv) {
    srand((unsigned)time(NULL));  // ���������ʱ�䲻ͬ����ͬ
//    for(int i = 0; i < 100; i++)
//        cout << rand()%100+1 << endl;
    char operators[4] = {'+','-','*','/'}; // ���������

    argv = 10;
    cout << "���ι���" << argv << "���⣬����100�֡�" << endl << endl;

    int rightNum = 0;   // ������ȷ�ĸ���
    int perScore = 100 / argv;  // ÿ����ռ�з���

    for(int i = 1; i <= argv; i++) {
        cout << i << ": ";
        int opNum = rand() % 10 + 1;  // ������ĸ���1-10
        int bracketNum = 0;  // ���ŵĸ���0-2
        if(opNum >= 4) {
            bracketNum = rand() % 3;
        }
        else if(opNum >= 2) {
            bracketNum = rand() % 2;
        }

        for(int j = 1; j <= opNum; j++) {
            int num = rand()%100+1;
            char op = operators[rand() % 4];
            cout << num << op;
        }
        int num = rand()%100+1;
        cout << num << endl;

        int ans;
//        cin >> ans;
//        int realAns = calc(a, oper, b);
//        if(ans == realAns) {
//            cout << "��ȷ��" << endl;
//            rightNum++;
//        }
//        else {
//            cout << "����ȷ����ȷ����" << realAns << endl;
//        }
    }
    int score = perScore * rightNum;
    cout << "���ε÷֣�" << score << "��" << endl;
    return 0;
}
