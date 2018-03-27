/*
��ʽ��ȫ��������f(n)=n!(����0!=1)

(A)�ֵ��򷨣�1��3��������ǰ�����123����������321����������ɨ�����������ģ���321�������������ҳ���һ�γ����½���λ�á�
(B)������λ������
(C)�ݼ���λ������
(D)��λ�Ի���������λ�����ֵĻ�λ�ǵ���ģ��������󣬶���λ�Ի����Ļ�λ��˫��ġ�
���뷨�ǽ���k��Ԫ��������ÿ��Ԫ�ؽ��н����������ȫ���С������㷨�ȽϽ�ʡ�ռ䡣

C++ STL���ṩ��std::next_permutation��std::prev_permutation���Ի�ȡ���ֻ������ַ���ȫ���У�
����std::next_permutation�ṩ����std::prev_permutation�ṩ����ע�������ȫ������ʼ��
*/

#include <bits/stdc++.h>
using namespace std;

void Perm(int arr[], int k, int m) //k��ʾǰ׺��λ��,m��Ҫ���е���Ŀ.
{
    if(k == m - 1) { //ǰ׺�����һ��λ��,��ʱ��ӡ������.
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        for(int i = k; i < m; i++) { //����ǰ׺,ʹ֮������һ��ǰ׺.
            swap(arr[k], arr[i]);
            Perm(arr, k + 1, m);
            swap(arr[k], arr[i]);   //��ǰ׺������,��������һ����ǰ׺����.
        }
    }
    return;
}

int main()
{
    int n, arr[1005], brr[1005]; cin >> n;
    for(int i = 1; i <= n; i++) arr[i - 1] = i;
    for(int i = 1; i <= n; i++) brr[i - 1] = n - i + 1;
    Perm(arr, 0, n);
    cout << endl;

    do {
        for(int i = 0; i < n; i++) cout << arr[i] << ' ';
        cout << endl;
    }while(next_permutation(arr, arr + n));
    cout << endl;

    do {
        for(int i = 0; i < n; i++) cout << brr[i] << ' ';
        cout << endl;
    }while(prev_permutation(brr, brr + n));
    cout << endl;
    return 0;
}
