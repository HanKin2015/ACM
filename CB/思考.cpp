#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "hejian"; //赋值1
    string hobby("basketball"); //赋值2
    string s1(name);    //复制1
    string s2 = name;   //复制2
    int n = 3;
    char ch = 'd';
    string s3(n, ch);   //ch只能是char型，不能是string型

    string s4 = "hello" + name;
    string s5 = "hello" + name + "master";
    //string s6 = "hello" + "master"; //错误

    cout << name << endl;
    cout << hobby << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    return 0;
}
