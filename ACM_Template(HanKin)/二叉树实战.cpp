/*
*一棵深度为k，且有2^k-1个节点的二叉树，称为满二叉树。
*除最后一层外，若其余层都是满的，并且最后一层或者是满的，或者是在右边缺少连续若干节点，则此二叉树为完全二叉树。
*节点数为n的完全二叉树深度为log2n+1。深度为k的完全二叉树，至少有2^(k-1)个节点，至多有2^k-1个节点。
https://blog.csdn.net/dongyanxia1000/article/details/52290065
*/
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#define MAX 20
using namespace std;

//顺序存储方式,用编号的方法从树根起，自上层至下层，每层自左至右地给所有结点编号。完全二叉树和满二叉树采用顺序存储比较合适。
/***  生成二叉树
思路：所有结点都需要和根结点比较大小，小于根结点的结点放在左子树，反之，
      大于根结点的结点放在右子树。
----- 本算法需要定义两个数组，数组b_tree用于存储最终的二叉树，数组node用于
      保存结点数值，为了使数组的下标和结点的编号相对应，b_tree[0]不存储数据，
      从b_tree[1]开始存储。
***/
void Create_bTree(int *b_tree, int *node, int len)
{
    b_tree[1] = node[1];
    for(int i = 2; i < len; i++) {
        int level = 1;
        while(b_tree[level] != 0) { //结点为空，退出循环，进行存储
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

//链表存储方式定义节点(最常用方法)
typedef int EmType;
#define long long LL
typedef struct BiTreeNode {
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
    EmType data;
} BiTreeNode, *BiTree; //*BiTree的意思是给 struct node*起了个别名，叫BiTree，故BiTree为指向节点的指针。

//按照前序顺序建立二叉树，中序和后序的都不能做到吧
void PreCreateBiTree(BiTree &T) //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{
    EmType c;
    cin >> c;
    if(0 == c) {           //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        T = NULL;
    } else {
        T = new BiTreeNode;
        T->data = c;
        PreCreateBiTree(T->lchild);
        PreCreateBiTree(T->rchild);
    }
    return;
}

//按照前序顺序建立二叉树(非输入版)
int cur = 0;  //这个很重要，是在每一次调用函数的时候增加
void _PreCreateBiTree(BiTree &T, int *node, int len)
{
    cur++;
    if(cur >= len) {
        return;
    }
    if(0 == node[cur]) {           //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        T = NULL;
    } else {
        T = new BiTreeNode;
        T->data = node[cur];
        _PreCreateBiTree(T->lchild, node, len);
        _PreCreateBiTree(T->rchild, node, len);
    }
    return;
}

//按照层次顺序建立二叉树(非输入版)
void LevelCreateBiTree(BiTree &T, int *node, int len, int cur)
{
    T = new BiTreeNode; //这样写会不会没有连接性，没有空间。应该先分配空间
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

//按照二叉排序树建立
void build(BiTree &T, int *node, int len)
{
    T = NULL;
    for(int i = 1; i < len; i++) {
        BiTreeNode *p = T;
        BiTreeNode *parNode;   //需要设置一个父亲节点，这样才能连接为整体
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
            //郁闷，始终没有长记性，又是忘记分配空间了
            BiTreeNode *q = new BiTreeNode;
            q->data = node[i];
            q->lchild = NULL;
            q->rchild = NULL;
            if(node[i] < parNode->data) {
                parNode->lchild = q;    //需要判断一下
            } else {
                parNode->rchild = q;
            }
        }
    }
    return;
}

//前序遍历二叉树并打印
void PreTraverse(BiTree T)
{
    if(T) {
        cout << T->data << " ";
        PreTraverse(T->lchild);
        PreTraverse(T->rchild);
    }
    return;
}
//中序遍历二叉树并打印
void MidTraverse(BiTree T)
{
    if(T) {
        MidTraverse(T->lchild);
        cout << T->data << " ";
        MidTraverse(T->rchild);
    }
    return;
}
//后序遍历二叉树并打印
void PostTraverse(BiTree T)
{
    if(T) {
        PostTraverse(T->lchild);
        PostTraverse(T->rchild);
        cout << T->data << " ";
    }
    return;
}

//按层序遍历二叉树并打印（这不就是宽度搜索嘛）
void LevelTraverse(BiTree T)
{
    cout << "层次遍历：";
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

//返回data域为x的结点指针(二分查找)
BiTree Find_Node(BiTree root, EmType x)
{
    BiTree p;
    if(root == NULL||root->data == x) {
        return root;
    } else if(x > root->data) {
        p = Find_Node(root->lchild, x);    //访问左子树
    } else {
        p = Find_Node(root->rchild, x);    //访问右子树
    }
    return p;
}
//统计二叉树的深度
/*
    当左子树的深度大于右子树时，则返回左子树的深度+1，否则返回右子树的深度+1
    当root为叶子结点时，停止递归，返回1，然后逐层向上累加。
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

//根据前序序列和中序序列建立二叉树
int num = 8, pre_p = 0;
int pre_s[] = {8, 7, 5, 4, 2, 6, 3, 1};
int mid_s[] = {5, 7, 2, 4, 8, 6, 1, 3};
//答案：5 2 4 7 1 3 6 8
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
    if(high - low < 0) { //该方向已经到尽头
        return;
    }
    t = new BiTreeNode;
    t->data = pre_s[pre_p];
    t->lchild = t->rchild = NULL;
    int pb = GetPosition();//求得前序序列中第pre_p个元素在中序序列中的位置
    pre_p++;
    CreatBinaryTree(t->lchild, low, pb - 1);//建立左子树
    CreatBinaryTree(t->rchild, pb + 1, high);//建立右子树
    return;
}

//不建树直接求出后序遍历序列
int index = 0;       //全局变量，用于遍历先序序列
/*测试数据，结果是GHDBIEFCA
String pre = new String("ABDGHCEIF");  //先序序列
String mid = new String("GDHBAEICF");  //中序序列
根据先序序列读取根节点，然后划分中序序列。
*/
void GetPost(int pre[], int mid[], int l, int r)
{
    if(r - l < 0) return;
    int pb = GetPosition();//求得前序序列中第pre_p个元素在中序序列中的位置
    int node = pre[pre_p++];
    GetPost(pre, mid, l, pb - 1);//递归处理左子树
    GetPost(pre, mid, pb + 1, r);//递归处理右子树
    cout << node << " ";
    return;
}

//非递归先序的话，用栈，先添加根，然后出栈判断是否有左右儿子，有的话先右后左入栈。
void _PreTraverse(BiTree T)
{
    cout << "非递归先序：";
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

//非递归中序
void _MidTraverse(BiTree T)
{
    cout << "非递归中序：";
    stack<BiTree> S;
    BiTree p = T;
//    while(p != NULL || !S.empty()){  //这是另外一个非递归先序遍历思路，稍微改一下就是中序
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
*后序遍历的非递归实现是三种遍历方式中最难的一种。
*因为在后序遍历中，要保证左孩子和右孩子都已被访问并且左孩子在右孩子前访问才能访问根结点。
*要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；
*或者P存 在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
*若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
*https://www.cnblogs.com/SHERO-Vae/p/5800363.html
*/
void _PostTraverse(BiTree T)
{
    cout << "非递归后序：";
    stack<BiTree> S;
    BiTree cur;                      //当前结点
    BiTree pre = NULL;               //前一次访问的结点
    S.push(T);
    while(!S.empty()) {
        cur = S.top();
        //这里非常巧妙，如果一个节点有左右孩子，则肯定左在右前面访问，而且右肯定在根前面访问，所以用或运算。
        if((cur->lchild == NULL && cur->rchild == NULL)|| \
           (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            cout << cur->data << " ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过
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
    int b_tree[MAX] = {0}; //初始为，全部为0
    int node[11] = {0, 8, 6, 7, 4, 2, 3, 15, 1, 14, 16};//8是根结点
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
    build(T, node, 11);   //按二叉排序树建树
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

    int pre[14] = {0, 1, 2, 0, 4, 0, 0, 3, 5, 0, 0, 6, 0, 0};//1是根结点
    int level[14] = {0, 1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 0, 0};//1是根结点
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
    //PreCreateBiTree(t);  //前序顺序建立，中序和后序很难实现
    //_PreCreateBiTree(t, pre, 14);  //前序顺序非输入
    LevelCreateBiTree(t, level, 14, 1); //按层次顺序输入
    PreTraverse(T);     cout << endl;
    MidTraverse(T);     cout << endl;
    PostTraverse(T);    cout << endl;
    LevelTraverse(T);   cout << endl;

    /*
    *已知二叉树先序序列和中序序列，求后序序列。
    */
    BiTreeNode *tree;
    CreatBinaryTree(tree, 0, 7);
    PostTraverse(tree); cout << endl;
    pre_p = 0;
    GetPost(pre_s, mid_s, 0, 7); cout << endl;

    /*
    *非递归先序、中序、后序
    */
    _PreTraverse(T);
    _MidTraverse(T);
    _PostTraverse(T);
    return 0;
}

