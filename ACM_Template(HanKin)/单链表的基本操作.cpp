/*
*���������ѧϰָ���ʹ��
*author: hankin
*date: 2018/03/25
*/
#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

//����������
typedef struct List
{
    ElemType data;              //�������е�������
    struct List *next;          //�������ָ����
}List, *linkList;  // ListΪ�ýṹ�����ͱ�����linkListΪ�ýṹ��ָ�����ͱ���

/*
*error: stray '\241' in program����
�������˼��c/c++�еĲ����˱������

�ô�����ָԴ�������зǷ��ַ�����Ҫ���Ƿ��ַ�ȥ����һ�������ڱ���ߣ����ó���Ա�����������Ϊ���ִ���̫�ͼ���ʹ���������뷨���ߴӱ�ĵط�ֱ�Ӹ���ճ��������ɵġ������г��������Ŀո��������ţ�
 �������ı����Ŷ�����֣����޸�һ�¾�OK�ˡ�

���������
1.�ѳ����еĿո���ǰ��ո�ɾ�����´�һ�����ԡ�
2.�����Ժ�������������ɫ��ͬ�ĸĵ������󲿷ֱ�����������ɫʶ��
3.ֱ��ȫ���ش�
*/
int initList(linkList *);    //��ʼ��һ������������ͷָ�룬ͷ��㣬ͷ���->next=NULL;
int createListHead(linkList *, int n);    //ͷ�巨����һ������������Ϊn��
int createListTail(linkList *, int n);  //β�巨����һ������������Ϊn��
int getlength(linkList *);      //��ȡ������ĳ��ȣ�
void printList(linkList *);      //��ӡ��������
int getElem(linkList *,int i,ElemType *);       //��ȡ�����е�i��λ�ô��ڵ������Ԫ�أ�
int insertList(linkList *, int i, ElemType data);       //�������ָ��λ�ã�i�ڵ㣩����һ���ڵ㣬i�ķ�ΧΪ1~length�������ܳ��ȣ���
int insertListTail(linkList *, ElemType data);      //������׷��һ���ڵ㣬����ĩβ�����ӣ�
int deleteList(linkList *, int i, ElemType *data);      //ɾ��ָ��λ�ã�i�ڵ㣩���Ľڵ㣬i�ķ�ΧΪ1~length�������ܳ��ȣ���
int clearList(linkList *);      //ɾ����������ʹͷ���->next=NULL;
int isEmpty(linkList *head);

int initList(linkList *head){
    *head = (linkList)malloc(sizeof(List));
    if((*head) == NULL){
        printf("�޷�����ռ䣬��ʼ��ʧ��\n");
        return 0;
    }
    (*head)->next = NULL;
    printf("��ʼ���ɹ�\n");
    return 1;
}

void inputList(linkList *head){
    linkList afterList = (*head);

    // �ҳ����β��,ʹ�ú��������ظ��������
    while(afterList->next != NULL){
        afterList = afterList->next;
    }

    int length = 0;
    printf("�����ݵ�����:\t");
    scanf("%d",&length);

    linkList p;
    // ��ν�һ��һ���ڵ��໥���� head->p->p1->p2->p3->null��
    int temp;
    while(length>0){
        p = (linkList)malloc(sizeof(List));
        scanf("%d",&temp);

        p->data = temp;             // ��������
        p->next = afterList->next;  // �������ɵĽڵ��next��ֵΪNULL
        afterList->next = p;        // ����һ���ڵ��nextָ�������ɵ�
        afterList = p;              // ���½ڵ����ɣ���afterListָ���½ڵ�

        length--;
        if(isEmpty(head) == 1){
            (*head)->next = p;      // ��֤ͷָ�룬ָ���һ���ڵ�
        }
    }
}

void insertByIndex(linkList *head,int index){
    linkList theNew = (linkList)malloc(sizeof(List));// �����ڵ�һ��Ҫͬʱ�����¿ռ�

    int data;
    printf("��������Ҫ�������:\t");
    scanf("%d",&data);

    linkList theAfter = (*head);//��ֹͷָ�뱻�ƻ�
    linkList theBefore;
    for(;index>0;index--){
        theBefore = theAfter;
        theAfter = theAfter->next;
    }
    theNew->data = data;
    theBefore->next = theNew;
    theNew->next = theAfter;
    printf("����ɹ�\n");
}

void deleteByIndex(linkList *head,int index){

    linkList theAfter = (*head);//��ֹͷָ�뱻�ƻ�
    linkList theBefore,temp;
    for(;index>0;index--){
        theBefore = theAfter;
        theAfter = theAfter->next;
    }
    theBefore->next = theAfter->next;
    free(theAfter);
    printf("ɾ���ɹ�\n");
}

void printList(linkList *head){
    printf("������Ϊ:\t");

    if(isEmpty(head) == 1){
        return;
    }

    linkList temp = (*head)->next;

    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp != NULL);

    printf("\n");
}

int getLength(linkList *head){

    int result = 0;

    if(isEmpty(head) == 1){
        return result;
    }

    linkList current = (*head)->next;
    do{
        result++;
        current = current->next;
    }while(current != NULL);

    printf("����Ϊ:%d\n",result);
    return result;
}

int isEmpty(linkList *head){
    if((*head)->next == NULL){
        //printf("��Ϊ��\n");
        return 1;
    }else{
        //printf("��Ϊ��\n");
        return 0;
    }
}

void test(linkList *t){
    printf("\n-------����-------\n");
    printf("self:%p\t",(*t));
    printf("data:%d\t",(*t)->data);
    printf("next:%p\n",(*t)->next);
    printf("-------����-------\n\n");
}

int main(int argc, char *argv[])
{
    linkList head;

    initList(&head);

    inputList(&head);

    printList(&head);

    insertByIndex(&head,3);

    printList(&head);

    deleteByIndex(&head,2);

    printList(&head);

    getLength(&head);

    return 0;
}
