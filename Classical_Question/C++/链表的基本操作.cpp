#include <bits/stdc++.h>
using namespace std;



int initList(linkList *);　　//初始化一个单链表，具有头指针，头结点，头结点->next=NULL;
int createListHead(linkList *, int n);　　//头插法创建一个链表，链表长度为n；
int createListTail(linkList *, int n);　　//尾插法创建一个链表，链表长度为n；
int getlength(linkList *);　　//获取单链表的长度；
int printList(linkList *);　　//打印整个链表；
int getElem(linkList *,int i,ElemType *);　　//获取链表中第i个位置处节点的数据元素；
int insertList(linkList *, int i, ElemType data);　　//在链表的指定位置（i节点）插入一个节点，i的范围为1~length（链表总长度）；
int insertListTail(linkList *, ElemType data);　　//给链表追加一个节点，在最末尾处增加；
int deleteList(linkList *, int i, ElemType *data);　　//删除指定位置（i节点）处的节点，i的范围为1~length（链表总长度）；
int clearList(linkList *);　　//删除整个链表，使头结点->next=NULL;

int initList(linkList *) {

}

int main()
{
    
    return 0;
}