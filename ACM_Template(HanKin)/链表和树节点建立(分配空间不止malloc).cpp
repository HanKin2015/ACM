#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode (int x): val(x), lChild(nullptr), rChild(nullptr) {}
};

/* 常用这种方式建立链表
typedef struct LinkNode {
public:
    int val;
    LinkNode* next;
    LinkNode (int x): val(x), next(nullptr) {}
}LinkNode, *LinkList;
*/

// 不建议这种，或者像树那样不生成对象
struct Node {
public:
    int val;
    Node* next;
    //LinkNode (int x): val(x), next(nullptr) {}
}LinkNode, *L;   // L已经是对象了

int main()
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = 520;
    p->next = nullptr;
    L = (Node*)malloc(sizeof(Node));
    L->next = p;

    Node* q = new Node;   // 直接使用new代码简练，注意没有括号
    if (!q) {             // 注意这些代码细节，决定成败
        cout << "分配不成功！" << endl;
        return -1;
    }
    q->val = 1314;
    q->next = NULL;
    p->next = q;
    return 0;
}
