# 多年呕心沥血之作
尽量在100字内总结，简短意赅。

## 1、数据结构
### 1-1、线段树
[线段树详解](http://blog.csdn.net/yitongjun/article/details/53193724)
[线段树从零开始](http://blog.csdn.net/zearot/article/details/52280189)
前缀和可以解决求和问题，但是无法快速进行修改。
将[1,n]分解成若干特定的子区间(数量不超过4*n),对区间内的一些点进行修改或统计操作，复杂度都是O(log2(n))。必须符合区间加法(分而治之)，否则，不可能通过分成的子区间来得到[L,R]的统计结果。 


```



```

### 1-2、树状数组

### 1-3、动态规划
铺地板系列

### 1-4、并查集
判断两个点是否可达？

### 1-5、链表
- 单链表的基本操作
- 单链表实战

### 1-6、马拉车算法

### 1-7、KMP算法

## 2、数论
### 2-1、判断素数
### 2-2、区间素数的数量
### 2-3、全排列(next_permutation与prev_permutation)
### 2-4、快速排序
### 2-5、组合公式{C(n,m)=C(n-1,m-1)+C(n-1,m)}

## 3、图论
### 3-1、最短路径
### 3-2、BFS
访问状态和队列，注意边界条件和循环停止。
- 迷宫问题
- 迷宫的最短路径
- bfs经典抓牛

### 3-3、DFS
状态和栈或者递归，状态记得恢复，注意边界条件和循环停止。
- 数水洼

### 3-4、回路

## 4、树
### 4-1、二叉树
- 一棵深度为k，且有2^k-1个节点的二叉树，称为满二叉树。
- 除最后一层外，若其余层都是满的，并且最后一层或者是满的，或者是在右边缺少连续若干节点，则此二叉树为完全二叉树。
- 节点数为n的完全二叉树深度为log2n+1。深度为k的完全二叉树，至少有2^(k-1)个节点，至多有2^k-1个节点。
- 二叉排序树（Binary Sort Tree），又称二叉查找树（Binary Search Tree），亦称二叉搜索树。
- 平衡二叉树又被称为AVL树（区别于AVL算法），它是一棵二叉排序树，且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
- 二叉排序树有排序要求，平衡二叉树有高度差要求。

#### 递归和非递归的实现
- 先序遍历
- 中序遍历
- 后序遍历
- 层序遍历
- 根据先序和中序求后序序列
- 前序建树
- 按照二叉排序树建树
- 层序建树

## 其他
- 多线程编程
- 多线程编程实战
- 清晰的多线程编程
- C++11多线程编程
- WindowsAPI多线程编程
- 虚函数和纯虚函数



