#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
// 1、在C++中，setw(int n)用来控制输出间隔,（n-1个空格）。

setw()默认填充的内容为空格，可以setfill()配合使用设置其他字符填充。

cout<<setfill('*')<<setw(5)<<'a'<<endl;
则输出：

****a //4个*和字符a共占5个位置。
    cout << setw(20) << "hello world" << endl;

/* C++数组
*Array 直接初始化 char 数组是特殊的,这种初始化要记得字符是以一个 null 结尾的。
*/
    char a1[] = {'C', '+', '+'};          // 初始化，没有 null
    char a2[] = {'C', '+', '+', '\0'};    // 初始化，明确有 null
    char a3[] = "C++";                    // null 终止符自动添加
    //const char a4[6] = "runoob";          // 报错，没有 null 的位置
    //a4 是错误的，虽然 a4 包括 6 个直接字符，但是 array 大小是 7：6个字符 + 一个null。正确的是:
    const char a4[7] = "runoob";

/* 3、C++字符串
*字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。
*由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。
*
*strcpy(s1, s2);复制字符串 s2 到字符串 s1。
*strcat(s1, s2);连接字符串 s2 到字符串 s1 的末尾。
*strlen(s1);返回字符串 s1 的长度。
*strcmp(s1, s2);如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
*strchr(s1, ch);返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
*strstr(s1, s2);返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
*
*string类提供了一系列针对字符串的操作，比如：
 1. append() -- 在字符串的末尾添加字符
 2. find() -- 在字符串中查找字符串
 4. insert() -- 插入字符
 5. length() -- 返回字符串的长度
 6. replace() -- 替换字符串
 7. substr() -- 返回某个子字符串
 8. ...
*/
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

/* 动态内存分配，没有指针是无法执行的。所以，想要成为一名优秀的 C++ 程序员，学习指针是很有必要的。
*/

    return 0;
}
