/*编程中无穷大的设定
很多人可能设为0x7fffffff,这个数的确是32-bit int的最大值，符号位为0，其他的都是1
但在很多情况下，0x7fffffff会出现错误，比如溢出，这样两个无穷大数相加会变成负数，还有如在做dijkstra求最短路时，当做松弛操作，判断if (d[u]+w[u][v]<d[v]) d[v]=d[u]+w[u][v]时，若u到v没有路劲，w[u][v]=0x7fffffff，这样d[u]+w[u][v]会变成负数，这就产生了错误。
为了尽量避免以上的错误，我们可以改变无穷大的设定，可以将0x3f3f3f3f设为无穷大，0x3f3f3f3f的10进制表示为1061109567，这个数已达到10^9，足以表示无穷大，又0x3f3f3f3f+0x3f3f3f3f=2122219134，满足无穷大+无穷大仍为无穷大
当把无穷大设为0x3f3f3f3f时，在做初始化时也很方便，比如在初始化数组a时，可以使用
Memset(a,0x3f,sizeof(a))，因为0x3f3f3f3f的每个字节都是0x3f，如果使用0x7fffffff，需要循环赋值，耗费更多时间*/
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
