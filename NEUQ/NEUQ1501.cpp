/*
�������뵽���ǿ϶��й��ɣ��ȴ��Ȼ����û��ʲô���֡�Ȼ��ӵ�ʽ������λ������������뵽�����ƣ�д��ǰ���飬�о���Щ���֡�
���������ÿһλȥ�ж������������̫���ӣ��������������Ȼ��������ǰ����һ���⣬������ʶ������x�Ķ������������k�Ķ����ơ�
*/
#include <iostream>
using namespace std;

int main()
{
    /*���x��1��ʼ�ĵ�5С��
    for(int i = 1; i < 10; i++) {
        cout << "x = " << i << ' ';
        int k = 0;
        for(int j = 1; ; j++) {
            if((i + j) == (i | j)) k++;
            if(k == 5) {
                cout << j <<endl;
                break;
            }
        }
    }
    */
    long long x, k, t; cin >> t;
    while(t--) {
        cin >> x >> k;
        int ans[55], bx[55], bk[55], dex = 0, dek = 0, tag = 0;
        while(x) {
            bx[dex++] = x % 2;
            x >>= 1;
        }
        while(k) {
            bk[dek++] = k % 2;
            k >>= 1;
        }
        int tmp = 0;
        for(int i = 0; i < dex; i++) {
            if(bx[i] == 1) ans[tag++] = 0;
            else if(tmp < dek) ans[tag++] = bk[tmp++];
        }
        while(tmp < dek) ans[tag++] = bk[tmp++];
        long long ret = 0, bin = 1;
        for(int i = 0; i < tag; i++) {
            ret += bin * ans[i];
            bin <<= 1;
        }
        cout << ret <<endl;
    }
    return 0;
}
