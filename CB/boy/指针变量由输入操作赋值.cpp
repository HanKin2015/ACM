#include <bits/stdc++.h>
//#pragma comment(linker,"/SECTION:.rdata,RW")
//加这句可以让常量区可写，后果自负！
using namespace std;

int main()
{
    char *S = NULL;  //指针一定要初始化，不然会成为野指针
    S = (char*)malloc(10*sizeof(char));
    cin >> S;
    cout << S << endl;

    // //下面的都是错误的操作，初始化为NULL,p=NULL,这样程序可以检查指针的值，不是NULL表示所指地址有效，可以使用，NULL表示无效,放弃使用。不初始化就是野指针，初始化为NULL就没有分配空间。
    char *p = NULL;
    scanf("%s",p);
    *p = '1';
    cout << p << endl;
    return 0;
}

