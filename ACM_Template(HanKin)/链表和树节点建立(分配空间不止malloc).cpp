#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode (int x): val(x), lChild(nullptr), rChild(nullptr) {}
};

/* �������ַ�ʽ��������
typedef struct LinkNode {
public:
    int val;
    LinkNode* next;
    LinkNode (int x): val(x), next(nullptr) {}
}LinkNode, *LinkList;
*/

// ���������֣������������������ɶ���
struct Node {
public:
    int val;
    Node* next;
    //LinkNode (int x): val(x), next(nullptr) {}
}LinkNode, *L;   // L�Ѿ��Ƕ�����

int main()
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = 520;
    p->next = nullptr;
    L = (Node*)malloc(sizeof(Node));
    L->next = p;

    Node* q = new Node;   // ֱ��ʹ��new���������ע��û������
    if (!q) {             // ע����Щ����ϸ�ڣ������ɰ�
        cout << "���䲻�ɹ���" << endl;
        return -1;
    }
    q->val = 1314;
    q->next = NULL;
    p->next = q;
    return 0;
}
