/*
��Ϊ�����������ṹ,��ֻ�ܴ�ͷ��β����,������ͷ��ʱ���õ��������β���ټ���,
��β��ʱ��Ҫ��һ��ָ��ָ��β���,����ͷ�巨ʱ�Ͳ�����ͷ�巨ʱ������������ݻ���
����������,���ʱ�����������ʱ���������,������������β�巨�����������˳��
һ�������Ƹ����Щ��ͷ�巨�������ڵ����ǲ���ͷ���������������ֵ����Ƶ����ͷ�塣
���ϣ����кô���
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
}ListNode, *LinkList;

//print element
void Display(LinkList L)
{
    while(L->next != NULL)  {
        L = L->next;
        cout << L->value << ' ';
    }
    return;
}

int main()
{
    List *L;
    L = (List *)malloc(sizeof(List));  //һ��Ҫ�ǵ÷����ڴ�
    if(L == NULL) cout << "�����ڴ�ռ�ʧ��" << endl;
    L->next = NULL;

    int x; cout << "�����������е�����(ctrl+z����): ";
    List *tail = L;  //β�巨���һ��βָ��
    while(cin >> x) {
        List *p;
        p = (List *)malloc(sizeof(List));   //�����µĽ�㣬��Ҫ�����·���ռ�
        p->value = x;
        /*
        *����β������ָ��NULL
        *����Lʼ����ͷ��
        */
        //p->next = L->next;  ͷ�巨
        //L->next = p;

        tail->next = p;
        //p->next = tail;  ����д�м�ͻ��п�ֵNULL��p  tail(NULL)  ��p  tail
        tail = p;
    }
    tail->next = NULL;
    Display(L);
    return 0;
}
