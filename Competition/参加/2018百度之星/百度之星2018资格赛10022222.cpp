#include <bits/stdc++.h>
#define maxn 100005     // 元素总个数 
using namespace std;

int min_character[maxn<<2], count[maxn<<2][26];       // min_character区间最小字母，count区间每个字母个数，开四倍空间
int A[maxn] n;                                        //存原数组下标[1，n]

//PushUp函数更新节点信息，这里是求和
void PushUp(int rt)
{
    Sum[rt] = min(Sum[rt<<1], Sum[rt<<1|1]);
}  

// Build函数建立线段树
void Build(int l, int r, int rt) // [l,r]表示当前节点区间，rt表示当前节点的实际存储位置 
{ 
    if (l==r) {//若到达叶节点 
        Sum[rt]=A[l];//存储A数组的值
        return;  
    }  
    int m=(l+r)>>1;  
   // 左右递归
    Build(l,m,rt<<1);  
    Build(m+1,r,rt<<1|1);  
    //更新信息
    PushUp(rt);  
}  

int Query(int L,int R,int l,int r,int rt){//[L,R]表示操作区间，[l,r]表示当前区间，rt:当前节点编号
    if(L <= l && r <= R){  
       //在区间内直接返回
        return Sum[rt];  
    }  
    int m=(l+r)>>1;  
    //左子区间:[l,m] 右子区间：[m+1,r]  求和区间:[L,R]
   //累加答案
    int ANS=1000;  
    if(L <= m) ANS =min(ANS, Query(L,R,l,m,rt<<1));//左子区间与[L,R]有重叠，递归
    if(R >  m) ANS =min(ANS, Query(L,R,m+1,r,rt<<1|1)); //右子区间与[L,R]有重叠，递归
    return ANS;  
}  

int main()
{
    n = 10;
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }
    Build(1, n, 1);
    int ans = Query(5, 8, 1, n, 1);
    cout << ans << endl;   // 26
    
    for (int i = 1; i < 40; i++) {
        cout << Sum[i] << ' ';
    }
    return 0;
}
