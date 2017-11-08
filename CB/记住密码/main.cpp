#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>
#include "INIParser.h"
using namespace std;

int main()
{
    CMyINI *p = new CMyINI();
    p->ReadINI("conf.ini");
//    cout <<endl<< "原始INI文件的内容：" << endl;
//    p->Travel();
//    p->SetValue("setting", "ImageLenth", "1280");
//    cout << endl << "增加节点之后的内容：" << endl;
//    p->Travel();
    cout << "\n修改节点之后的内容：" << endl;
    p->SetValue("User", "userName", "hejian");
    p->SetValue("User", "userPassword", "123456");
    p->Travel();
    p->WriteINI("Setting.ini");
    cout << p->GetValue("User", "userName") << endl;
    return 0;
}
