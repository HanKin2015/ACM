#include <bits/stdc++.h>
#define eps 1e-6
using namespace std;

const int maxn = 505;
int n, m;  //n是系数的个数，m是多项式的个数
//a是系数（等式左边），b是结果（等式右边），value是未知数（答案）
double a[maxn*2][maxn], b[maxn*2], value[maxn];

void GaoSi()
{
    // 处理出上三角矩阵
    for(int i = 1; i <= n; i++) {
        bool flag = false;
        for(int j = i; j <= m; j++) {   // 从第i行开始，找到第i列不等于0的行j
            if(abs(a[j][i]) > eps) {
                //swap(j, i);      // 智障一样的存在，交换第i行和第j行
                for(int k = 1; k <= n; k++) {
                    swap(a[i][k], a[j][k]);
                }
                swap(b[i], b[j]);
                flag = true;
                break;
            }
        }
        // 若无法找到，则存在多个解
        if(!flag) {
            cout << "Many solutions" << endl;
            return;
        }
        // 消除第i+1行到第M行的第i列
        for(int j = i + 1; j <= m; j++) {
            double temp = a[j][i] / a[i][i];
            for(int k = i; k <= n; k++) {
                a[j][k] = a[j][k] - a[i][k] * temp;
            }
            b[j] = b[j] - b[i] * temp;
        }
    }

    // 检查是否无解，即存在 0 = x 的情况
    for(int i = 1; i <= m; i++) {
        bool flag = true;    //第i行系数是否都为0
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

    // 此时存在唯一解
    // 由于每一行都比前一行少一个系数，所以在M行中只有前N行有系数(因为M大于等于N，多项式的个数大于等于未知数个数）
    // 解析来从第N行开始处理每一行的解
    for(int i = n; i > 0; i--) {
        // 利用已经计算出的结果，将第i行中第i+1列至第N列的系数消除
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


