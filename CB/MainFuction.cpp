#include <string.h>
#include <stdio.h>
#include <cstdlib>
#define pi 3.1415926
int main(int argc, char **argv)
{
    if(argc < 2) {
        printf("����������������Ҫ�������룡\n");
        printf("USAGE: ./MainFunction [password] [others]\n");
        return 0;
    }
    if(strcmp(argv[1],"pass")!=0)//���ÿ���ıȽ�
    {
        printf("password error!\n");
        exit(0);
    }
    printf("success\n");
    printf("��������Ϊ%d\n", argc);
    return 0;
}
