/*
*二分查找
*查找不大于查询值的最大值。
*/
#include <bits/stdc++.h>
using namespace std;

//折半查找记得要先排序
//数组作为参数传递时，实际上传递的是一个指针，采用sizeof的方法，获取到的是指针的长度。
template<class T>  //模板编程就行了
bool binary_find(T &arr, int n)
{
    int len = sizeof(arr) / sizeof(arr[0]);  //函数里传递的时候不能这样求
    cout << len << endl;
    int l = 0, r = len - 1;
    while(l < r) {
        int mid = (l + r) / 2;cout << arr[mid] << endl;
        if(arr[mid] > n) r = mid - 1;
        else if(arr[mid] < n) l = mid + 1;
        else return true;
    }
    return false;
}

int main()
{
    //int arr[7] = {5, 6, 7, 9, 12, 1, 3 };
    int arr[3] = {1, 10, 100};
    int q = 10;          //返回答案6
    int len = sizeof(arr) / sizeof(int);  //计算数组长度的大小
    cout << "数组大小 = " << len << endl;
    //二分查找一定要记得先排序
    sort(arr, arr + len);
    int l = 0, r = len - 1;   //第一个注意点r是否取得到？因为l能取，所以r亦可。
    while(l <= r) {      //条件这里很重要，本问题取等于，取r（左边），最好模拟一下
        int mid = (r + l) / 2;
        if(arr[mid] > q) r = mid - 1;  //注意左右需要加减
        else if(arr[mid] < q) l = mid + 1;
        else {
            r = mid;    //mid是答案
            break;
        }
    }
    cout << arr[r] << endl;
    cout << boolalpha << binary_find(arr, 10) << endl;

    /*
    STL中关于二分查找的函数有三个lower_bound 、upper_bound 、binary_search 。运用于有序区间（二分查找的前提）。
    lower_bound算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
    upper_bound算法返回一个非递减序列[first, last)中的第一个大于值val的位置。
    */
    int a[] = {1, 2, 3, 3, 4, 5, 6, 6, 7};
    auto pos1 = lower_bound(a, a + 9, 3);  //所以上面那个题用lower_bound很快做出来
    cout << pos1 - a << endl;  //a直接是数组第一个元素的地址
    auto pos2 = upper_bound(a, a + 9, 3);
    cout << pos2 - a << endl;  //a直接是数组第一个元素的地址
    auto pos3 = binary_search(a, a + 9, 3);  //这个查找返回值为bool值
    cout << pos3 << endl;  //a直接是数组第一个元素的地址
    return 0;
}
