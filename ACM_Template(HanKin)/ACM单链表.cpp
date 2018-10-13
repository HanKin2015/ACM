/*
思考：第一个要不要是空节点???
 
链表区分带头节点和不带头结点两种。假定链表节点指向下一节点的指针变量名为next。那么区分情况，判断空链表的方法为：
 
1 带头节点。
对于带头节点的链表，存在有不变的头结点head，这个节点并不保存任何数据，仅提供链表起始的一个标识。对于此类链表，判断为空的条件为head->next==NULL。当head的next值为NULL,这时链表为空。
 
2 不带头结点。
不带头结点的情况，链表的起始节点是可能变化的，但无论如何变化，必须有一个节点指针类型的变量保存实际上的第一个节点first。
当first为空时，链表即为空。这时判断为空的条件为first==NULL。
 
***统一要一个头节点***
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e4 + 5;
 
 // 这种方法不建议使用
struct Node {
    int val;
    Node *next;
    //Node (int x): val(x), next(nullptr) {}   这种形式写会报错
}LinkNode, *LinkList;    // LinkNode和LinkList已经是实例化对象，不能当作类型使用
 
typedef struct ListNode {  // typedef写就不会出错
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
}ListNode, *ListList;    
 
void ListBuild(ListList L, int arr[], int len)
{
    ListNode *p = L;
    //int len = sizeof(arr) / sizeof(arr[0]); // 对了,作为参数的时候不能这样做
    //cout << len << endl;
    for (int i = 0; i < len; i++) {
        ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = arr[i];
        tmp->next = NULL;
        p->next = tmp;
        p = tmp;
    }
    return;
}
 
void Display(ListList L)
{
    while (NULL != L->next) {
        L = L->next;
        cout << L->val << endl;
    }
    return;
}
 
int main()
{
    #define BUG
    #ifdef BUG
        freopen("data.in", "r", stdin);
    #endif // BUG
    int arr[] = {6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    ListList L;     // 这是typedef定义的struct结构类型
    L = (ListNode*)malloc(sizeof(ListNode));
    ListBuild(L, arr, len);
    Display(L);
    return 0;
}
 