#include <bits/stdc++.h>
//#pragma comment(linker,"/SECTION:.rdata,RW")
//���������ó�������д������Ը���
using namespace std;

int main()
{
    char *S = NULL;  //ָ��һ��Ҫ��ʼ������Ȼ���ΪҰָ��
    S = (char*)malloc(10*sizeof(char));
    cin >> S;
    cout << S << endl;

    // //����Ķ��Ǵ���Ĳ�������ʼ��ΪNULL,p=NULL,����������Լ��ָ���ֵ������NULL��ʾ��ָ��ַ��Ч������ʹ�ã�NULL��ʾ��Ч,����ʹ�á�����ʼ������Ұָ�룬��ʼ��ΪNULL��û�з���ռ䡣
    char *p = NULL;
    scanf("%s",p);
    *p = '1';
    cout << p << endl;
    return 0;
}

