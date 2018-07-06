#include <bits/stdc++.h>
using namespace std;

class T
{
    public:
     ~T(){cout<<"析构函数被调用。";} //为了简洁，函数体可以直接写在定义的后面，此时函数为内联函数
};

int main()
{
    //对了对于/需要转移，\则不需要？？？
    char *a = "abcddsdsde";
    char b[] = "abcde";
    char c = 'a';
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    //使用regex_replace 实现trim功能，去掉字符串前后的空白字符
    regex reg1("^(\\s)*");
    regex reg2("\\s*$");

    string test_str("  abc  \t");
    string t("");
    test_str = regex_replace(test_str,reg1,t); //trim_left
    test_str = regex_replace(test_str,reg2,t); //trim_right

    T *tt = new T();//建立一个T类的指针对象t
    //delete tt;
    //cin.get();
    return 0;
}
