/*������������趨
�ܶ��˿�����Ϊ0x7fffffff,�������ȷ��32-bit int�����ֵ������λΪ0�������Ķ���1
���ںܶ�����£�0x7fffffff����ִ��󣬱�������������������������ӻ��ɸ���������������dijkstra�����·ʱ�������ɳڲ������ж�if (d[u]+w[u][v]<d[v]) d[v]=d[u]+w[u][v]ʱ����u��vû��·����w[u][v]=0x7fffffff������d[u]+w[u][v]���ɸ�������Ͳ����˴���
Ϊ�˾����������ϵĴ������ǿ��Ըı��������趨�����Խ�0x3f3f3f3f��Ϊ�����0x3f3f3f3f��10���Ʊ�ʾΪ1061109567��������Ѵﵽ10^9�����Ա�ʾ�������0x3f3f3f3f+0x3f3f3f3f=2122219134�����������+�������Ϊ�����
�����������Ϊ0x3f3f3f3fʱ��������ʼ��ʱҲ�ܷ��㣬�����ڳ�ʼ������aʱ������ʹ��
Memset(a,0x3f,sizeof(a))����Ϊ0x3f3f3f3f��ÿ���ֽڶ���0x3f�����ʹ��0x7fffffff����Ҫѭ����ֵ���ķѸ���ʱ��*/
#include<stdio.h>
#include<string.h>
#define MAX1 0x7fffffff
#define MAX2 0x3f3f3f3f
int a[3];
int main()
{
    memset(a,0x3f,sizeof(a));
    printf("%d\n",MAX1);
    printf("%d\n",MAX1*2);
    printf("%d\n",MAX2);
    printf("%d\n",MAX2*2);
    for(int i=0;i<3;i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}
