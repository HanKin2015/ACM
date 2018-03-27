/*
*һ�����Ϊk������2^k-1���ڵ�Ķ���������Ϊ����������
*�����һ���⣬������㶼�����ģ��������һ����������ģ����������ұ�ȱ���������ɽڵ㣬��˶�����Ϊ��ȫ��������
*�ڵ���Ϊn����ȫ���������Ϊlog2n+1�����Ϊk����ȫ��������������2^(k-1)���ڵ㣬������2^k-1���ڵ㡣
https://blog.csdn.net/dongyanxia1000/article/details/52290065
*/
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#define MAX 20
using namespace std;

//˳��洢��ʽ,�ñ�ŵķ��������������ϲ����²㣬ÿ���������ҵظ����н���š���ȫ��������������������˳��洢�ȽϺ��ʡ�
/***  ���ɶ�����
˼·�����н�㶼��Ҫ�͸����Ƚϴ�С��С�ڸ����Ľ���������������֮��
      ���ڸ����Ľ�������������
----- ���㷨��Ҫ�����������飬����b_tree���ڴ洢���յĶ�����������node����
      ��������ֵ��Ϊ��ʹ������±�ͽ��ı�����Ӧ��b_tree[0]���洢���ݣ�
      ��b_tree[1]��ʼ�洢��
***/
void Create_bTree(int *b_tree, int *node, int len)
{
    b_tree[1] = node[1];
    for(int i = 2; i < len; i++) {
        int level = 1;
        while(b_tree[level] != 0) { //���Ϊ�գ��˳�ѭ�������д洢
            if(node[i] < b_tree[level]) {
                level = 2 * level;
            } else {
                level = 2 * level + 1;
            }
        }
        b_tree[level] = node[i];
    }
    return;
}

//����洢��ʽ����ڵ�(��÷���)
typedef int EmType;
#define long long LL
typedef struct BiTreeNode {
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
    EmType data;
} BiTreeNode, *BiTree; //*BiTree����˼�Ǹ� struct node*���˸���������BiTree����BiTreeΪָ��ڵ��ָ�롣

//����ǰ��˳����������������ͺ���Ķ�����������
void PreCreateBiTree(BiTree &T) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
    EmType c;
    cin >> c;
    if(0 == c) {           //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
        T = NULL;
    } else {
        T = new BiTreeNode;
        T->data = c;
        PreCreateBiTree(T->lchild);
        PreCreateBiTree(T->rchild);
    }
    return;
}

//����ǰ��˳����������(�������)
int cur = 0;  //�������Ҫ������ÿһ�ε��ú�����ʱ������
void _PreCreateBiTree(BiTree &T, int *node, int len)
{
    cur++;
    if(cur >= len) {
        return;
    }
    if(0 == node[cur]) {           //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
        T = NULL;
    } else {
        T = new BiTreeNode;
        T->data = node[cur];
        _PreCreateBiTree(T->lchild, node, len);
        _PreCreateBiTree(T->rchild, node, len);
    }
    return;
}

//���ղ��˳����������(�������)
void LevelCreateBiTree(BiTree &T, int *node, int len, int cur)
{
    T = new BiTreeNode; //����д�᲻��û�������ԣ�û�пռ䡣Ӧ���ȷ���ռ�
    T->data = node[cur];
    if (node[cur * 2] == 0 || cur * 2 >= len) {
        T->lchild = NULL;
    } else {
        T->lchild = new BiTreeNode;
        LevelCreateBiTree(T->lchild, node, len, cur * 2);
    }
    if (node[cur * 2 + 1] == 0 || cur * 2 + 1 >= len) {
        T->rchild = NULL;
    } else {
        T->rchild = new BiTreeNode;
        LevelCreateBiTree(T->rchild, node, len, cur * 2 + 1);
    }
    return;
}

//���ն�������������
void build(BiTree &T, int *node, int len)
{
    T = NULL;
    for(int i = 1; i < len; i++) {
        BiTreeNode *p = T;
        BiTreeNode *parNode;   //��Ҫ����һ�����׽ڵ㣬������������Ϊ����
        if(T == NULL) {
            T = new BiTreeNode;
            T->data = node[i];
            T->lchild = NULL;
            T->rchild = NULL;
        } else {
            while(p != NULL) {
                parNode = p;
                if(node[i] < p->data) {
                    p = p->lchild;
                } else {
                    p = p->rchild;
                }
            }
            //���ƣ�ʼ��û�г����ԣ��������Ƿ���ռ���
            BiTreeNode *q = new BiTreeNode;
            q->data = node[i];
            q->lchild = NULL;
            q->rchild = NULL;
            if(node[i] < parNode->data) {
                parNode->lchild = q;    //��Ҫ�ж�һ��
            } else {
                parNode->rchild = q;
            }
        }
    }
    return;
}

//ǰ���������������ӡ
void PreTraverse(BiTree T)
{
    if(T) {
        cout << T->data << " ";
        PreTraverse(T->lchild);
        PreTraverse(T->rchild);
    }
    return;
}
//�����������������ӡ
void MidTraverse(BiTree T)
{
    if(T) {
        MidTraverse(T->lchild);
        cout << T->data << " ";
        MidTraverse(T->rchild);
    }
    return;
}
//�����������������ӡ
void PostTraverse(BiTree T)
{
    if(T) {
        PostTraverse(T->lchild);
        PostTraverse(T->rchild);
        cout << T->data << " ";
    }
    return;
}

//�������������������ӡ���ⲻ���ǿ�������
void LevelTraverse(BiTree T)
{
    cout << "��α�����";
    queue<BiTree> Q;
    Q.push(T);
    while(!Q.empty()) {
        BiTree node = Q.front();
        Q.pop();
        cout << node->data << " ";
        if(node->lchild) {
            Q.push(node->lchild);
        }
        if(node->rchild) {
            Q.push(node->rchild);
        }
    }
    cout << endl;
    return;
}

//����data��Ϊx�Ľ��ָ��(���ֲ���)
BiTree Find_Node(BiTree root, EmType x)
{
    BiTree p;
    if(root == NULL||root->data == x) {
        return root;
    } else if(x > root->data) {
        p = Find_Node(root->lchild, x);    //����������
    } else {
        p = Find_Node(root->rchild, x);    //����������
    }
    return p;
}
//ͳ�ƶ����������
/*
    ������������ȴ���������ʱ���򷵻������������+1�����򷵻������������+1
    ��rootΪҶ�ӽ��ʱ��ֹͣ�ݹ飬����1��Ȼ����������ۼӡ�
*/
int BTDepth(BiTree root)
{
    int ldepth, rdepth;
    if(root==NULL) {
        return 0;
    } else {
        ldepth = BTDepth(root->lchild);
        rdepth = BTDepth(root->rchild);
        return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
    }
}

//����ǰ�����к��������н���������
int num = 8, pre_p = 0;
int pre_s[] = {8, 7, 5, 4, 2, 6, 3, 1};
int mid_s[] = {5, 7, 2, 4, 8, 6, 1, 3};
//�𰸣�5 2 4 7 1 3 6 8
int GetPosition()
{
    for(int i = 0; i < num; ++i) {
        if(mid_s[i] == pre_s[pre_p]) {
            return i;
        }
    }
    return 0;
}

void CreatBinaryTree(BiTree &t, int low, int high)
{
    if(high - low < 0) { //�÷����Ѿ�����ͷ
        return;
    }
    t = new BiTreeNode;
    t->data = pre_s[pre_p];
    t->lchild = t->rchild = NULL;
    int pb = GetPosition();//���ǰ�������е�pre_p��Ԫ�������������е�λ��
    pre_p++;
    CreatBinaryTree(t->lchild, low, pb - 1);//����������
    CreatBinaryTree(t->rchild, pb + 1, high);//����������
    return;
}

//������ֱ����������������
int index = 0;       //ȫ�ֱ��������ڱ�����������
/*�������ݣ������GHDBIEFCA
String pre = new String("ABDGHCEIF");  //��������
String mid = new String("GDHBAEICF");  //��������
�����������ж�ȡ���ڵ㣬Ȼ�󻮷��������С�
*/
void GetPost(int pre[], int mid[], int l, int r)
{
    if(r - l < 0) return;
    int pb = GetPosition();//���ǰ�������е�pre_p��Ԫ�������������е�λ��
    int node = pre[pre_p++];
    GetPost(pre, mid, l, pb - 1);//�ݹ鴦��������
    GetPost(pre, mid, pb + 1, r);//�ݹ鴦��������
    cout << node << " ";
    return;
}

//�ǵݹ�����Ļ�����ջ������Ӹ���Ȼ���ջ�ж��Ƿ������Ҷ��ӣ��еĻ����Һ�����ջ��
void _PreTraverse(BiTree T)
{
    cout << "�ǵݹ�����";
    stack<BiTree> S;
    S.push(T);
    while(!S.empty()) {
        BiTree node = S.top();
        S.pop();
        if(node->rchild) S.push(node->rchild);
        if(node->lchild) S.push(node->lchild);
        cout << node->data << " ";
    }
    cout << endl;
    return;
}

//�ǵݹ�����
void _MidTraverse(BiTree T)
{
    cout << "�ǵݹ�����";
    stack<BiTree> S;
    BiTree p = T;
//    while(p != NULL || !S.empty()){  //��������һ���ǵݹ��������˼·����΢��һ�¾�������
//        while(p != NULL) {
//            cout << p->data << " ";
//            S.push(p);
//            p = p->lchild;
//        }
//        if(!S.empty()){
//            p = S.top();
//            S.pop();
//            p = p->rchild;
//        }
//    }
    while(p != NULL || !S.empty()){
        while(p != NULL) {
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty()){
            p = S.top();
            S.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
    return;
}

/*
*��������ķǵݹ�ʵ�������ֱ�����ʽ�����ѵ�һ�֡�
*��Ϊ�ں�������У�Ҫ��֤���Ӻ��Һ��Ӷ��ѱ����ʲ����������Һ���ǰ���ʲ��ܷ��ʸ���㡣
*Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
*����P�� �����ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
*�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
*https://www.cnblogs.com/SHERO-Vae/p/5800363.html
*/
void _PostTraverse(BiTree T)
{
    cout << "�ǵݹ����";
    stack<BiTree> S;
    BiTree cur;                      //��ǰ���
    BiTree pre = NULL;               //ǰһ�η��ʵĽ��
    S.push(T);
    while(!S.empty()) {
        cur = S.top();
        //����ǳ�������һ���ڵ������Һ��ӣ���϶�������ǰ����ʣ������ҿ϶��ڸ�ǰ����ʣ������û����㡣
        if((cur->lchild == NULL && cur->rchild == NULL)|| \
           (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << " ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ�
            S.pop();
            pre = cur;
        }
        else {
            if(cur->rchild != NULL) S.push(cur->rchild);
            if(cur->lchild != NULL) S.push(cur->lchild);
        }
    }
    cout << endl;
    return;
}

int main()
{
    int b_tree[MAX] = {0}; //��ʼΪ��ȫ��Ϊ0
    int node[11] = {0, 8, 6, 7, 4, 2, 3, 15, 1, 14, 16};//8�Ǹ����
    Create_bTree(b_tree, node, 11);
    int high = 0, cnt = 0;
    for(int i = 1; i < MAX; i++) {
        cout << b_tree[i] << "\t";
        cnt++;
        if(cnt == pow(2, high)) {
            cout << endl;
            high++;
            cnt = 0;
        }
    }
    cout << endl << endl;

    BiTreeNode *T;
    build(T, node, 11);   //����������������
    /*
              8
           6    15
          4 7 14  16
         2
        1 3
    *
    *8 6 4 2 1 3 7 15 14 16
    *1 2 3 4 6 7 8 14 15 16
    *1 3 2 4 7 6 14 16 15 8
    */

    int pre[14] = {0, 1, 2, 0, 4, 0, 0, 3, 5, 0, 0, 6, 0, 0};//1�Ǹ����
    int level[14] = {0, 1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 0, 0};//1�Ǹ����
    /*
          1
       2     3
         4 5   6
    *
    *1 2 4 3 5 6
    *2 4 1 5 3 6
    *4 2 5 6 3 1
    */
    BiTreeNode *t;
    //PreCreateBiTree(t);  //ǰ��˳����������ͺ������ʵ��
    //_PreCreateBiTree(t, pre, 14);  //ǰ��˳�������
    LevelCreateBiTree(t, level, 14, 1); //�����˳������
    PreTraverse(T);     cout << endl;
    MidTraverse(T);     cout << endl;
    PostTraverse(T);    cout << endl;
    LevelTraverse(T);   cout << endl;

    /*
    *��֪�������������к��������У���������С�
    */
    BiTreeNode *tree;
    CreatBinaryTree(tree, 0, 7);
    PostTraverse(tree); cout << endl;
    pre_p = 0;
    GetPost(pre_s, mid_s, 0, 7); cout << endl;

    /*
    *�ǵݹ��������򡢺���
    */
    _PreTraverse(T);
    _MidTraverse(T);
    _PostTraverse(T);
    return 0;
}

