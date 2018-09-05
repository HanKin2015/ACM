#include <bits/stdc++.h>
using namespace std;
 
typedef int ElemType;
 
typedef struct DulNode {
    ElemType data;
    struct DulNode *prior, *next;
    DulNode(int val): data(val), prior(NULL), next(NULL) {}
}DulNode, *DulLinkList;
 
/* 带头结点的双向循环链表的建立 */
void DulLinkListBuild(DulLinkList DL, int arr[], int len)
{
    DL->next = DL->prior = DL;
    DulNode *p = DL;
    for (int i = 0; i < len; i++) {
        DulNode *tmp = (DulNode*)malloc(sizeof(DulNode));
        tmp->data = arr[i];
        tmp->next = DL;
        DL->prior = tmp;    /* 注意这几步 */
        tmp->prior = p;
        p->next = tmp;
        p = tmp;
    }
    return;
}
 
/* 头部插入一个数据 */
void DulLinkListHeadInsert(DulLinkList DL, int val)
{
    DulNode *tmp = (DulNode*)malloc(sizeof(DulNode));
    tmp->data = val;
    tmp->next = DL->next;
    tmp->prior = DL;
    DL->next = tmp;
    return;
}
 
/* 尾部插入一个数据 */
void DulLinkListTailInsert(DulLinkList DL, int val)
{
    DulNode *tmp = (DulNode*)malloc(sizeof(DulNode));
    tmp->data = val;
    tmp->next = DL;
    tmp->prior = DL->prior;
    DL->prior->next = tmp;
   DL->prior = tmp;
    return;
}
 
/* 正序打印 */
void Display1(DulLinkList DL)
{
    DulNode *p = DL->next;     /* p指向头节点下一个节点 */
    while   (p != DL) {
        cout << p->data << ' ';
        p=p->next;
    }
    cout << endl;
    return;
}
 
/* 逆序打印 */
void Display2(DulLinkList DL)
{
    DulNode *p = DL->prior;    /* p指向头节点前一个节点即尾节点 */
    while   (p != DL) {
        cout << p->data << ' ';
        p=p->prior;
    }
    cout << endl;
    return;
}
 
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
 
    DulLinkList DL;
    DL = (DulLinkList)malloc(sizeof(DulNode));
 
    DulLinkListBuild(DL, arr, len);
 
    Display1(DL);   /* 正序 */
    Display2(DL);   /* 逆序 */
 
    DulLinkListTailInsert(DL, 8);
    Display1(DL);
 
    DulLinkListHeadInsert(DL, 88);
    Display1(DL);
    return 0;
}