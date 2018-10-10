#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

string operators[4] = {"+", "-", "*", "/"}; // 四则运算符

// 比较两个操作符的优先级
int judge(string op1, string op2) {
    if(op1 == "(") return -1;
    else if(op1 == "+" || op1 == "-") {
        if(op2 == "*" || op2 == "/")  return -1;
        else return 0;
    }
    if(op1 == "*" || op1 == "/") {
        if(op2 == "+" || op2 == "-") return 1;
        else return 0;
    }
}

bool IsOperator(string str) {
    for(int i = 0; i < 4; i++) {
        if(str == operators[i])
            return true;
    }
    return false;
}

// 后缀表达式求值程序
int Calculate(queue<string> postFix) {
    stack<string> S;

    while(!postFix.empty()) {
        string tmp = postFix.front();
        if(!IsOperator(tmp)) {  // 如果是数字就进栈
            S.push(tmp);
        }
        else {
            string strA, strB;
            int intA, intB;
            int ans;
            char* end;

            strB = S.top();
            intB = static_cast<int>(strtol(strB.c_str(),&end,10));
            S.pop();
            strA = S.top();
            intA = static_cast<int>(strtol(strA.c_str(),&end,10));
            S.pop();

            if(tmp == "+") ans = intA + intB;
            else if(tmp == "-") ans = intA - intB;
            else if(tmp == "*") ans = intA * intB;
            else ans = intA / intB;

            stringstream ss;
            int t = ans;
//            cout << t << endl;
            ss << ans;
            S.push(ss.str());
            ss.str("");
        }
        postFix.pop();
    }
    cout << S.top() << endl;
    return 0;
}

// 中缀表达式转换成后缀表达式
void Infix_to_Postfix(queue<string> inFix) {
    queue<string> Q;
    stack<string> S;

    while(!inFix.empty()) {
        string  str = inFix.front();
        if(str == "(") S.push(str);
        else if(str == ")") {
            while(S.top() != "(") {
                Q.push(S.top());
                S.pop();
            }
            S.pop();
        }
        else {
            if(!IsOperator(str))
                S.push(str);
            else {
                while(!S.empty() && judge(S.top(), str) >= 0) {
                    Q.push(S.top());
                    S.pop();
                }
                S.push(str);
            }
        }
        inFix.pop();
    }

    while(!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
    Calculate(Q);

//    cout << "后缀表达式：" << endl;
//    while(!Q.empty()) {
//        cout << Q.front() << " ";
//        Q.pop();
//    }
//    cout << endl;
    return ;
}

void Infix_to_Queue(char formula[]) {
    queue<string> inFix;
    int len = strlen(formula);
    string str = "";
    for(int i = 0; i < len; i++) {
        if(formula[i] > '9' || formula[i] < '0') {
            if(str != "") {
                inFix.push(str);
                str = "";
            }
            str += formula[i];
            inFix.push(str);
            str = "";
            continue;
        }
        str += formula[i];
    }
    if(str != "") inFix.push(str);

    Infix_to_Postfix(inFix);

//    while(!inFix.empty()) {
//        str = inFix.front();
//        cout << str << " ";
//        inFix.pop();
//    }
    return ;
}

int main()
{
    char formula[105];
    cin >> formula;
    Infix_to_Queue(formula);
    return 0;
}
