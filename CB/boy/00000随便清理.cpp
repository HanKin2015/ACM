#include <bits/stdc++.h>
using namespace std;

class T
{
    public:
     ~T(){cout<<"�������������á�";} //Ϊ�˼�࣬���������ֱ��д�ڶ���ĺ��棬��ʱ����Ϊ��������
};

int main()
{
    //���˶���/��Ҫת�ƣ�\����Ҫ������
    char *a = "abcddsdsde";
    char b[] = "abcde";
    char c = 'a';
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    //ʹ��regex_replace ʵ��trim���ܣ�ȥ���ַ���ǰ��Ŀհ��ַ�
    regex reg1("^(\\s)*");
    regex reg2("\\s*$");

    string test_str("  abc  \t");
    string t("");
    test_str = regex_replace(test_str,reg1,t); //trim_left
    test_str = regex_replace(test_str,reg2,t); //trim_right

    T *tt = new T();//����һ��T���ָ�����t
    //delete tt;
    //cin.get();
    return 0;
}
