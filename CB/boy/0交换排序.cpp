#include <bits/stdc++.h>
using namespace std;

/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */
extern void swap_with_zero(int* array, int len, int n);

void swap_with_zero(int* array, int len, int n)
{
    int pos0, posn;
    for(int i = 0; i < len; i++)
    {
        if(array[i] == 0) pos0 = i;
        if(array[i] == n) posn = i;
    }
    swap(array[pos0], array[posn]);
    return;
}

class Solution
{
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int* array, int len)
    {

        for(int i = len - 1; i > 0; i --) {
            if(array[i] == i) continue;  //判断是否在正确位置
            swap_with_zero(array, len, array[i]);   //交换0与i位置的数字 
            swap_with_zero(array, len, i);  //交换0与i
        }
        /*愚蠢还没做正确
        for(int k = 0; k < 2; k++) {
            for(int i = 0; i < len; i++)
            {
                for(int j = i; j < len; j++)
                {
                    if(array[0] == 0) swap(array[0], array[j]);
                    if(array[j] == 0)
                    {
                        swap_with_zero(array, len, j);
                        break;
                    }
                }
            }
        }
        */
    }
};

int main()
{
    Solution hankin;
    int array[] = {3, 8, 2, 4, 5, 0, 1, 7, 9, 6};
    int len = sizeof(array) / sizeof(int);
    hankin.sort(array, len);
    for(int i = 0; i < len; i++) cout << array[i] << ' ';
    cout << endl;
    return 0;
}
