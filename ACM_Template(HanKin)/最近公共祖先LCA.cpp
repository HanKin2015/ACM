/*
最近公共祖先LCA(Lowest Common Ancestors)
对于有根树T的两个结点u、v，最近公共祖先LCA(T,u,v)表示一个结点x，满足x是u、v的祖先且x的深度尽可能大。

一个满K叉树，从根节点1开始从上往下，从左往右编号，求最近公共祖先。
*/
#include <bits/bits/stdc++.h>
using namespace std;

// 倍增法
int LCA1(int a, int b)
{
    int father1 = (a + k - 2) / k, father2 = (b + k - 2) / k;
    while (father1 != father2) {

    }
}

int main()
{

    return 0;
}
