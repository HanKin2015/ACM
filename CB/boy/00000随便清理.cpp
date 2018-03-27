#include <bits/stdc++.h>
using namespace std;

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
    return 0;
}
