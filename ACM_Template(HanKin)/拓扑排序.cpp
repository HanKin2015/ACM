/*
提示：跟一般的排序不一样，这个用于有向无环图

对一个有向无环图(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，
使得图中任意一对顶点u和v，若边(u,v)∈E(G)，则u在线性序列中出现在v之前。

拓扑排序对应施工的流程图具有特别重要的作用，它可以决定哪些子工程必须要先执行，哪些子工程要在某
些工程执行后才可以执行。
*/

queue<int>q;
//priority_queue<int,vector<int>,greater<int>>q;
//优先队列的话，会按照数值大小有顺序的输出
//此处为了理解，暂时就用简单队列
int topo()
{
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    int temp;
    while(!q.empty())
    {
        temp=q.front();//如果是优先队列，这里可以是top()
        printf("%d->",temp);
        q.pop();
        for(int i=1;i<=n;i++)//遍历从temp出发的每一条边，入度--
        {
            if(map[temp][i])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
    }
}
