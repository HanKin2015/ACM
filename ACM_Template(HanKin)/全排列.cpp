/*
公式：全排列种数f(n)=n!(定义0!=1)

(A)字典序法：1—3的排列最前面的是123，最后面的是321，从右向左扫描若都是增的，即321，结束。否则找出第一次出现下降的位置。
(B)递增进位制数法
(C)递减进位制数法
(D)邻位对换法：减进位制数字的换位是单向的，从右向左，而邻位对换法的换位是双向的。
其想法是将第k个元素与后面的每个元素进行交换，求出其全排列。这种算法比较节省空间。

C++ STL中提供了std::next_permutation与std::prev_permutation可以获取数字或者是字符的全排列，
其中std::next_permutation提供升序、std::prev_permutation提供降序。注意必须完全递增开始。
*/

#include <bits/stdc++.h>
using namespace std;

void Perm(int arr[], int k, int m) //k表示前缀的位置,m是要排列的数目.
{
    if(k == m - 1) { //前缀是最后一个位置,此时打印排列数.
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        for(int i = k; i < m; i++) { //交换前缀,使之产生下一个前缀.
            swap(arr[k], arr[i]);
            Perm(arr, k + 1, m);
            swap(arr[k], arr[i]);   //将前缀换回来,继续做上一个的前缀排列.
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
