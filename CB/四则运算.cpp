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
    srand((unsigned)time(NULL));  // 随机数根据时间不同而不同
//    for(int i = 0; i < 100; i++)
//        cout << rand()%100+1 << endl;
    char operators[4] = {'+','-','*','/'}; // 四则运算符

    argv = 10;
    cout << "本次共有" << argv << "道题，满分100分。" << endl << endl;

    int rightNum = 0;   // 计算正确的个数
    int perScore = 100 / argv;  // 每道题占有分数

    for(int i = 1; i <= argv; i++) {
        cout << i << ": ";
        int opNum = rand() % 10 + 1;  // 运算符的个数1-10
        int bracketNum = 0;  // 括号的个数0-2
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
//            cout << "正确！" << endl;
//            rightNum++;
//        }
//        else {
//            cout << "不正确！正确答案是" << realAns << endl;
//        }
    }
    int score = perScore * rightNum;
    cout << "本次得分：" << score << "分" << endl;
    return 0;
}
