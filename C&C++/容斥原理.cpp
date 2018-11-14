#include <bits/stdc++.h>
#define LL long long
using namespace std;

// ��n��������
void FindPrimeFactor(int n, int a[], int &cnt)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a[cnt++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) a[cnt++] = n;
    return;
}

// ���Ӷ�Ҳ��2^k
LL Solve2(LL n, int a[], int cnt)
{
    LL res = 0;
    int t = 1, que[1005] = { -1}; // �����ݳ�ԭ��que[0]��ֵ��-1
    for (int i = 0; i < cnt; i++) {  // ����2 3 4���γ�-1 2 3 -6 4 -8 -12 24
        int k = t;
        for (int j = 0; j < k; j++) {
            que[t++] = que[j] * a[i] * (-1);  // �ѵ�
            /*����-1��-1^k��һ����Ч��
            �ص��ڵ�һ��forѭ�����¼ӽ�ȥ������ǰ���γ�����Ӵ�*/
        }
    }
    cout << "t = " << t << endl;
    for (int i = 1; i < t; i++) {
        cout << que[i] << endl;
        res += n / que[i];
    }
    return res;
}

int solve (int n, int r)
{
    /*������*/
    vector<int> p;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) p.push_back (n);

    int sum = 0;   // �ǻ��ʵĸ���
    for (int msk = 1; msk < (1 << (int)p.size()); msk++) {  // �Ӵ���2^k�ֿ���
        int mult = 1, bits = 0;
        /*ÿ�ֿ�����bitλ��ʾ�����kλ��Ȼ��bitλ���Ƿ��γ����*/
        for (int i = 0; i < (int)p.size(); ++i) {
            if (msk & (1 << i)) {
                ++bits;
                mult *= p[i];
            }
        }
        int cur = r / mult;
        //cout << cur << endl;
        if (bits % 2 == 1) sum += cur;
        else sum -= cur;
    }
    return r - sum;
}

/*
��Ŀ������һ������[A,B],�ҳ�������������������N���ʵ������ĸ�����
T(0 < T <= 100)the number of test cases
each of the next T lines contains three integers A, B, N where (1 <= A <= B <= 10^15) and (1 <=N <= 10^9).

ֱ�����ʸ��Ӷȸߣ�����������ɸѡ����ǻ��ʵ�����
��[1,B]-[1,A-1]��
*/

// ֱ����һ���д��󣬱���ʹ���ݳ�ԭ��
LL Solve(LL n, int a[], int cnt)
{
    LL res = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; ; j++) {
            if (j * a[i] > n) {
                res += j - 1;
                break;
            }
        }
    }
    return res;
}
/*
N = 12 --- 2 3
18  2 4 6 8 10 12 14 16 18
    3 6 9 12 15 18
�᷵�ؽ��Ϊ15.
��ȷ����12.
*/

int main()
{
    const int maxn = 1005;
    int a[maxn] = {2, 3, 4}, cnt = 3;
    //FindPrimeFactor(12, a, cnt);
    //cout << Solve2(18, a, cnt) << endl;
    cout << solve(12, 18) << endl;

    __int64 i, T, x, y, n, sum;
    while(scanf("%I64d", &T) != EOF) {
        for(i = 1; i <= T; i++) {
            scanf("%I64d%I64d%I64d", &x, &y, &n);
            //sum = y - haha(y) - (x - 1 - haha(x - 1)); //����������[x,y],���[1,y]�Ļ��ʸ������ټ�ȥ[1,x-1]�Ļ��ʸ���
            printf("Case #%I64d: ", i);
            printf("%I64d\n", sum);
        }
    }
    return 0;
}
