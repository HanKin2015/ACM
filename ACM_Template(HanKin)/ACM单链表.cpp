/*
˼������һ��Ҫ��Ҫ�ǿսڵ�???
 
�������ִ�ͷ�ڵ�Ͳ���ͷ������֡��ٶ�����ڵ�ָ����һ�ڵ��ָ�������Ϊnext����ô����������жϿ�����ķ���Ϊ��
 
1 ��ͷ�ڵ㡣
���ڴ�ͷ�ڵ�����������в����ͷ���head������ڵ㲢�������κ����ݣ����ṩ������ʼ��һ����ʶ�����ڴ��������ж�Ϊ�յ�����Ϊhead->next==NULL����head��nextֵΪNULL,��ʱ����Ϊ�ա�
 
2 ����ͷ��㡣
����ͷ����������������ʼ�ڵ��ǿ��ܱ仯�ģ���������α仯��������һ���ڵ�ָ�����͵ı�������ʵ���ϵĵ�һ���ڵ�first��
��firstΪ��ʱ������Ϊ�ա���ʱ�ж�Ϊ�յ�����Ϊfirst==NULL��
 
***ͳһҪһ��ͷ�ڵ�***
*/
#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e4 + 5;
 
 // ���ַ���������ʹ��
struct Node {
    int val;
    Node *next;
    //Node (int x): val(x), next(nullptr) {}   ������ʽд�ᱨ��
}LinkNode, *LinkList;    // LinkNode��LinkList�Ѿ���ʵ�������󣬲��ܵ�������ʹ��
 
typedef struct ListNode {  // typedefд�Ͳ������
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
}ListNode, *ListList;    
 
void ListBuild(ListList L, int arr[], int len)
{
    ListNode *p = L;
    //int len = sizeof(arr) / sizeof(arr[0]); // ����,��Ϊ������ʱ����������
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
    ListList L;     // ����typedef�����struct�ṹ����
    L = (ListNode*)malloc(sizeof(ListNode));
    ListBuild(L, arr, len);
    Display(L);
    return 0;
}
 