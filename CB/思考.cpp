#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "hejian"; //��ֵ1
    string hobby("basketball"); //��ֵ2
    string s1(name);    //����1
    string s2 = name;   //����2
    int n = 3;
    char ch = 'd';
    string s3(n, ch);   //chֻ����char�ͣ�������string��

    string s4 = "hello" + name;
    string s5 = "hello" + name + "master";
    //string s6 = "hello" + "master"; //����

    cout << name << endl;
    cout << hobby << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    return 0;
}
