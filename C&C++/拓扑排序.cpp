/*
��ʾ����һ�������һ����������������޻�ͼ

��һ�������޻�ͼ(Directed Acyclic Graph���DAG)G�������������ǽ�G�����ж����ų�һ���������У�
ʹ��ͼ������һ�Զ���u��v������(u,v)��E(G)����u�����������г�����v֮ǰ��

���������Ӧʩ��������ͼ�����ر���Ҫ�����ã������Ծ�����Щ�ӹ��̱���Ҫ��ִ�У���Щ�ӹ���Ҫ��ĳ
Щ����ִ�к�ſ���ִ�С�
*/

queue<int>q;
//priority_queue<int,vector<int>,greater<int>>q;
//���ȶ��еĻ����ᰴ����ֵ��С��˳������
//�˴�Ϊ����⣬��ʱ���ü򵥶���
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
        temp=q.front();//��������ȶ��У����������top()
        printf("%d->",temp);
        q.pop();
        for(int i=1;i<=n;i++)//������temp������ÿһ���ߣ����--
        {
            if(map[temp][i])
            {
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
    }
}
