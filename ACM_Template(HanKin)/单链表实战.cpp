/*
因为单链表的特殊结构,即只能从头向尾遍历,所以向头插时所用的语句会比向尾插少几个,
向尾插时还要多一个指针指向尾结点,而用头插法时就不但用头插法时最先输入的数据会排
在链表的最后,输出时即变成了输入时的逆序输出,看起来不如用尾插法那样和输入的顺序
一样的形势更舒服些。头插法是新增节点总是插在头部，所以如果对新值访问频繁就头插。
综上，各有好处。
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
    L = (List *)malloc(sizeof(List));  //一定要记得分配内存
    if(L == NULL) cout << "申请内存空间失败" << endl;
    L->next = NULL;

    int x; cout << "请输入链表中的数字(ctrl+z结束): ";
    List *tail = L;  //尾插法会多一个尾指针
    while(cin >> x) {
        List *p;
        p = (List *)malloc(sizeof(List));   //申请新的结点，不要忘记新分配空间
        p->value = x;
        /*
        *链表尾部必须指向NULL
        *并且L始终是头部
        */
        //p->next = L->next;  头插法
        //L->next = p;

        tail->next = p;
        //p->next = tail;  这样写中间就会有空值NULL，p  tail(NULL)  新p  tail
        tail = p;
    }
    tail->next = NULL;
    Display(L);
    return 0;
}
