/*
*˼·��ǰ׺��˼�� + ���ֲ���
*��ʼ�Թ����ѶȽ�������Ȼ�����ﵽ��ǰ�Ѷȵ���߱��ꡣ�����ݶ��ֲ�������Ĺ����Ѷ������߱��ꡣ
*/
#include <iostream>
#include <algorithm>
#define maxn 100005
using namespace std;

struct jobStrcut{
    int D, P;
    int maxP = 0;
};

bool cmp(jobStrcut a, jobStrcut b) {
    return a.D < b.D;
}

int main()
{
    int N, M;
    while(cin >> N >> M) {
        jobStrcut job[maxn];
        for(int i = 0; i < N; i++) {
            cin >> job[i].D >> job[i].P;
        }
        sort(job, job + N, cmp);
        int temp = -100;
        for(int i = 0; i < N; i++) {
            if(job[i].P > temp) temp = job[i].P;
            job[i].maxP = temp;
        }
        for(int i = 0; i < M; i++) {
            int A; cin >> A;
            int l = 0, r = N - 1;  //ʹ���±�ȽϺã��������������Ӧ���Ѷȣ����Ѷȿ���û�����ֵ
            while(l <= r) {
                int mid = (l + r) / 2;
                if(A > job[mid].D) l = mid + 1;
                else if(A < job[mid].D) r = mid - 1;
                else {
                    r = mid;
                    break;
                }
            }
            cout << job[r].maxP << endl;
        }
    }
    return 0;
}
