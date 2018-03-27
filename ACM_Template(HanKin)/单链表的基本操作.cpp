/*
*单链表可以学习指针的使用
*author: hankin
*date: 2018/03/25
*/
#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

//定义结点类型
typedef struct List
{
    ElemType data;              //单链表中的数据域
    struct List *next;          //单链表的指针域
}List, *linkList;  // List为该结构体类型别名，linkList为该结构体指针类型别名

/*
*error: stray '\241' in program错误
报错的意思是c/c++中的产生了编译错误。

该错误是指源程序中有非法字符，需要将非法字符去掉。一般是由于编程者（不用程序员这个名词是因为这种错误太低级）使用中文输入法或者从别的地方直接复制粘贴代码造成的。代码中出现了中文空格，中文引号，
 各种中文标点符号都会出现，简单修改一下就OK了。

解决方法：
1.把出错行的空格及其前后空格删掉重新打一下试试。
2.把明显和其他标点符号颜色不同的改掉。（大部分编译器都有颜色识别）
3.直接全部重打。
*/
int initList(linkList *);    //初始化一个单链表，具有头指针，头结点，头结点->next=NULL;
int createListHead(linkList *, int n);    //头插法创建一个链表，链表长度为n；
int createListTail(linkList *, int n);  //尾插法创建一个链表，链表长度为n；
int getlength(linkList *);      //获取单链表的长度；
void printList(linkList *);      //打印整个链表；
int getElem(linkList *,int i,ElemType *);       //获取链表中第i个位置处节点的数据元素；
int insertList(linkList *, int i, ElemType data);       //在链表的指定位置（i节点）插入一个节点，i的范围为1~length（链表总长度）；
int insertListTail(linkList *, ElemType data);      //给链表追加一个节点，在最末尾处增加；
int deleteList(linkList *, int i, ElemType *data);      //删除指定位置（i节点）处的节点，i的范围为1~length（链表总长度）；
int clearList(linkList *);      //删除整个链表，使头结点->next=NULL;
int isEmpty(linkList *head);

int initList(linkList *head){
    *head = (linkList)malloc(sizeof(List));
    if((*head) == NULL){
        printf("无法分配空间，初始化失败\n");
        return 0;
    }
    (*head)->next = NULL;
    printf("初始化成功\n");
    return 1;
}

void inputList(linkList *head){
    linkList afterList = (*head);

    // 找出表的尾部,使得函数可以重复添加数据
    while(afterList->next != NULL){
        afterList = afterList->next;
    }

    int length = 0;
    printf("新数据的数量:\t");
    scanf("%d",&length);

    linkList p;
    // 如何将一个一个节点相互连接 head->p->p1->p2->p3->null？
    int temp;
    while(length>0){
        p = (linkList)malloc(sizeof(List));
        scanf("%d",&temp);

        p->data = temp;             // 存入数据
        p->next = afterList->next;  // 将新生成的节点的next赋值为NULL
        afterList->next = p;        // 将上一个节点的next指向新生成的
        afterList = p;              // 有新节点生成，将afterList指向新节点

        length--;
        if(isEmpty(head) == 1){
            (*head)->next = p;      // 保证头指针，指向第一个节点
        }
    }
}

void insertByIndex(linkList *head,int index){
    linkList theNew = (linkList)malloc(sizeof(List));// 新增节点一定要同时分配新空间

    int data;
    printf("请输入需要插入的数:\t");
    scanf("%d",&data);

    linkList theAfter = (*head);//防止头指针被破坏
    linkList theBefore;
    for(;index>0;index--){
        theBefore = theAfter;
        theAfter = theAfter->next;
    }
    theNew->data = data;
    theBefore->next = theNew;
    theNew->next = theAfter;
    printf("插入成功\n");
}

void deleteByIndex(linkList *head,int index){

    linkList theAfter = (*head);//防止头指针被破坏
    linkList theBefore,temp;
    for(;index>0;index--){
        theBefore = theAfter;
        theAfter = theAfter->next;
    }
    theBefore->next = theAfter->next;
    free(theAfter);
    printf("删除成功\n");
}

void printList(linkList *head){
    printf("表数据为:\t");

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

    printf("表长度为:%d\n",result);
    return result;
}

int isEmpty(linkList *head){
    if((*head)->next == NULL){
        //printf("表为空\n");
        return 1;
    }else{
        //printf("表不为空\n");
        return 0;
    }
}

void test(linkList *t){
    printf("\n-------测试-------\n");
    printf("self:%p\t",(*t));
    printf("data:%d\t",(*t)->data);
    printf("next:%p\n",(*t)->next);
    printf("-------结束-------\n\n");
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
