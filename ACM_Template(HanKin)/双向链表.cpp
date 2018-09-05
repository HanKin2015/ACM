#include <bits/stdc++.h>
using namespace std;
 
typedef int ElemType;
 
typedef struct DulNode {
    ElemType data;
    struct DulNode *prior, *next;
    DulNode(int val): data(val), prior(NULL), next(NULL) {}
}DulNode, *DulLinkList;
 
/* ��ͷ����˫��ѭ������Ľ��� */
void DulLinkListBuild(DulLinkList DL, int arr[], int len)
{
    DL->next = DL->prior = DL;
    DulNode *p = DL;
    for (int i = 0; i < len; i++) {
        DulNode *tmp = (DulNode*)malloc(sizeof(DulNode));
        tmp->data = arr[i];
        tmp->next = DL;
        DL->prior = tmp;    /* ע���⼸�� */
        tmp->prior = p;
        p->next = tmp;
        p = tmp;
    }
    return;
}
 
/* ͷ������һ������ */
void DulLinkListHeadInsert(DulLinkList DL, int val)
{
    DulNode *tmp = (DulNode*)malloc(sizeof(DulNode));
    tmp->data = val;
    tmp->next = DL->next;
    tmp->prior = DL;
    DL->next = tmp;
    return;
}
 
/* β������һ������ */
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
 
/* �����ӡ */
void Display1(DulLinkList DL)
{
    DulNode *p = DL->next;     /* pָ��ͷ�ڵ���һ���ڵ� */
    while   (p != DL) {
        cout << p->data << ' ';
        p=p->next;
    }
    cout << endl;
    return;
}
 
/* �����ӡ */
void Display2(DulLinkList DL)
{
    DulNode *p = DL->prior;    /* pָ��ͷ�ڵ�ǰһ���ڵ㼴β�ڵ� */
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
 
    Display1(DL);   /* ���� */
    Display2(DL);   /* ���� */
 
    DulLinkListTailInsert(DL, 8);
    Display1(DL);
 
    DulLinkListHeadInsert(DL, 88);
    Display1(DL);
    return 0;
}