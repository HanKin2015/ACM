#include <bits/stdc++.h>
#define eps 1e-6
using namespace std;

const int maxn = 505;
int n, m;  //n��ϵ���ĸ�����m�Ƕ���ʽ�ĸ���
//a��ϵ������ʽ��ߣ���b�ǽ������ʽ�ұߣ���value��δ֪�����𰸣�
double a[maxn*2][maxn], b[maxn*2], value[maxn];

void GaoSi()
{
    // ����������Ǿ���
    for(int i = 1; i <= n; i++) {
        bool flag = false;
        for(int j = i; j <= m; j++) {   // �ӵ�i�п�ʼ���ҵ���i�в�����0����j
            if(abs(a[j][i]) > eps) {
                //swap(j, i);      // ����һ���Ĵ��ڣ�������i�к͵�j��
                for(int k = 1; k <= n; k++) {
                    swap(a[i][k], a[j][k]);
                }
                swap(b[i], b[j]);
                flag = true;
                break;
            }
        }
        // ���޷��ҵ�������ڶ����
        if(!flag) {
            cout << "Many solutions" << endl;
            return;
        }
        // ������i+1�е���M�еĵ�i��
        for(int j = i + 1; j <= m; j++) {
            double temp = a[j][i] / a[i][i];
            for(int k = i; k <= n; k++) {
                a[j][k] = a[j][k] - a[i][k] * temp;
            }
            b[j] = b[j] - b[i] * temp;
        }
    }

    // ����Ƿ��޽⣬������ 0 = x �����
    for(int i = 1; i <= m; i++) {
        bool flag = true;    //��i��ϵ���Ƿ�Ϊ0
        for(int j = 1; j <= n; j++) {
            if(abs(a[i][j]) > eps) {
                flag = false;
                break;
            }
        }
        if(flag && abs(b[i]) > eps) {
            cout << "No solutions" << endl;
            return;
        }
    }

    // ��ʱ����Ψһ��
    // ����ÿһ�ж���ǰһ����һ��ϵ����������M����ֻ��ǰN����ϵ��(��ΪM���ڵ���N������ʽ�ĸ������ڵ���δ֪��������
    // �������ӵ�N�п�ʼ����ÿһ�еĽ�
    for(int i = n; i > 0; i--) {
        // �����Ѿ�������Ľ��������i���е�i+1������N�е�ϵ������
        for(int j = i + 1; j <= n; j++) {
            b[i] = b[i] - a[i][j] * value[j];
            a[i][j] = 0;
        }
        value[i] = int(b[i] / a[i][i] + 0.5);
    }
    for(int i = 1; i <= n; i++) {
        cout << value[i] << endl;
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    GaoSi();
    return 0;
}

/*
4 4
1 1 2 1 22
3 2 1 1 24
4 1 2 1 28
7 3 2 1 40

2 3 5 7
*/


