#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int status = 1 << m;  // �������Ե���ϣ�ȡ���߲�ȡ���ö����Ʊ�ʾ״̬����״̬ѹ��
        static int f[1005][1 << 11]; // ��ʾ��ǰi����Ʒ��ѡ�����ɸ���������ż����s��������ܴﵽ����߼�ֵ
        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int v, s, st = 0;
            cin >> v >> s;
            for (int j = 0; j < s; j++) {
                int attr;
                cin >> attr;
                st |= 1 << (attr - 1);  // ��ÿ����Ʒӵ�е�����λ��ֵΪ1���޵�Ϊ0
            }
            for (int t = 0; t < status; t++) {
                if (!f[i - 1][t]) {
                    // ȡ��ǰ��Ʒ����ż�Է����仯��Ӧ�����
                    f[i][t ^ st] = max(f[i][t ^ st], f[i - 1][t] + v);
                    // ��ȡ��ǰ��Ʒ
                    f[i][t] = max(f[i][t], f[i - 1][t]);
                    //f[i][t | st] = max(f[i - 1][t | st], f[i - 1][t] + v);
                }
            }
        }
        cout << max(f[n][status - 1], 0) << endl;
     }
    return 0;
}
