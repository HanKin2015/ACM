/*
首先我想到的是肯定有规律，先打表，然而并没有什么发现。然后从等式发现有位运算操作就联想到二进制，写了前两组，感觉有些发现。
但是如果从每一位去判断两种情况还是太复杂，不好做。结果忽然间想起以前做的一道题，似曾相识，就是x的二进制里面插入k的二进制。
*/
#include <iostream>
using namespace std;

int main()
{
    /*打表，x从1开始的第5小数
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
