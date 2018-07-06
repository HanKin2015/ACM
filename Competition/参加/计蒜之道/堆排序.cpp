#include <bits/stdc++.h>
using namespace std;

/*ע�⣺�������ֻ���ڵ�����������λ��Ϊ����ѣ�δ�����ķ�֧���ᴦ��
���Բ��ܽ�һ���Ǵ���Ѷ������ĸ���㴫�ݹ���������������䴦��Ϊ�����*/
void heap_ajust(intint *a, int i, int size)  /*aΪ�Ѵ洢���飬sizeΪ�ѵĴ�С*/
{
    int lchild = 2*i;       //i�����ӽڵ����
    int rchild = 2*i +1;     //i���Һ��ӽڵ����
    int max = i; /*����������������������±�*/
    int temp;
    if(i <= size/2)          //���i��Ҷ�ڵ�Ͳ��ý��е���
    {
        if(lchild<=size && a[lchild]>a[max])
        {
            max = lchild;
        }
        if(rchild<=size && a[rchild]>a[max])
        {
            max = rchild;
        }
        if(max != i)
        {
            temp = a[i]; /*����a[i]��a[max]��ֵ*/
            a[i] = a[max];
            a[max] = temp;
            heap_ajust(a, max, size); /*��������λ����ǰ�Ǵ���ѣ����ڿ��ܲ��Ǵ����
                                        ������Ҫ���µ���ʹ���Ϊ����ѽṹ*/
        }
    }
}

void build_bheap(intint *a, int size) /*���������*/
{
    int i;
    for(i=size/2; i >= 1; i--) /*��Ҷ�ڵ�������ֵΪsize/2*/
    {
        heap_ajust(a, i, size); /*ÿ����Ҷ�ӽ�㶼��Ҫ�����������*/
    }
}

void heap_sort(intint *a, int size) /*������*/
{
    int i;
    int temp;

    build_bheap(a, size);
    for(i=size; i >= 1; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp; /*�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������*/
        heap_ajust(a, 1, i-1); /*���µ����Ѷ��ڵ��Ϊ�󶥶ѣ�ֻ�б������ķ�֧���п��ܲ��Ǵ����*/
    }
}

int main()
{
    int a[]={0,16,20,3,11,17,8};
    int size = sizeof(a)/sizeof(int) -1;
    int i;

    printf("size = %d\n", size);
    heap_sort(a, size);
    printf("Sort over:");
    for(i=1;i <= size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
