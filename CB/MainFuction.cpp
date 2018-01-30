#include <string.h>
#include <stdio.h>
#include <cstdlib>
#define pi 3.1415926
int main(int argc, char **argv)
{
    if(argc < 2) {
        printf("参数数量不够！需要输入密码！\n");
        printf("USAGE: ./MainFunction [password] [others]\n");
        return 0;
    }
    if(strcmp(argv[1],"pass")!=0)//设置口令的比较
    {
        printf("password error!\n");
        exit(0);
    }
    printf("success\n");
    printf("参数数量为%d\n", argc);
    return 0;
}
